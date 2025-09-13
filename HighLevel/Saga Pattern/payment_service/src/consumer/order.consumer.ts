import { pool } from "../db";
import { createConsumer, producer } from "../kafka";

const simulatePayment = (amount: number): string => {
  // Simulate payment processing logic
  return amount <= 2000 ? "SUCCESS" : "FAILED";
};

export const startOrderConsumer = async () => {
  try {
    const consumer = createConsumer("payment-service-order-group");
    await consumer.connect();
    await producer.connect();
    await consumer.subscribe({ topic: "order-events", fromBeginning: true });

    await consumer.run({
      eachMessage: async ({ message }) => {
        if (!message.value) return;
        const payload = JSON.parse(message.value.toString());
        console.log("Received order event:", payload);

        // processing this order event to make payment and check has sufficient balance
        const { orderId, userId, productId, price } = payload;
        const paymentStatus = simulatePayment(price);

        // update to payment table
        await pool.query(
          `INSERT INTO payments(order_id, user_id, product_id, price, payment_status) VALUES($1,$2,$3,$4,$5)`,
          [orderId, userId, productId, price, paymentStatus]
        );

        // Produce payment event to Kafka
        const msg = { orderId, userId, productId, price, paymentStatus };
        await producer.send({
          topic: "payment-events",
          messages: [{ key: orderId, value: JSON.stringify(msg) }],
        });

        console.log("[PaymentService] produced payment-event:", msg);
      },
    });
  } catch (error) {
    console.error("Error starting order consumer:", error);
    throw error;
  }
};
