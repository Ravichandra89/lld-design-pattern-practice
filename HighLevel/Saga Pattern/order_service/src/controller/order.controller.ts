import { Request, Response } from "express";
import { v4 as uuidv4 } from "uuid";
import { pool } from "../db";
import { producer } from "../kafka";

export const createOrder = async (req: Request, res: Response) => {
  try {
    const { userId, productId, price } = req.body;
    if (!userId || !productId || !price) {
      return res.status(400).json({
        message: "Missing required fields",
      });
    }

    const orderId = uuidv4(); // make unique order id
    await pool.query(
      `
            INSERT INTO orders(order_id, user_id, product_id, price, status) VALUES($1,$2,$3,$4,$5)
        `,
      [orderId, userId, productId, price, "PENDING"]
    );

    // produce an event to kafka topic -> Paymentservice
    const message = {
      orderId,
      userId,
      productId,
      price,
    };

    await producer.send({
      topic: "order-events",
      messages: [
        {
          key: orderId,
          value: JSON.stringify(message),
        },
      ],
    });

    res.status(201).json({
      message: "Order created successfully",
      orderId,
    });
  } catch (error) {
    console.error("Error creating order:", error);
    res.status(500).json({
      message: "Internal Server Error",
    });
  }
};
