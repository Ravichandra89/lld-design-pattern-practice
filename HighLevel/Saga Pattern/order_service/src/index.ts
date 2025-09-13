import express from "express";
import dotenv from "dotenv";
import { createProducer, createConsumer } from "./kafka";
import { initilizeDb } from "./db";
import { createOrder } from "./controller/order.controller";
import { startPaymentConsumer } from "./consumers/payment.consumer";

dotenv.config();

// create express server
const app = express();
app.use(express.json());
app.use(express.urlencoded({ extended: true }));

const port = process.env.PORT || 3000;

// Bootstrap all the method to run them parallel
const bootstrap = async () => {
  try {
    await initilizeDb();
    await createProducer();
    await createConsumer("order-service-group");
    await startPaymentConsumer();
    app.listen(port, () => {
      console.log(`Order Service is running on port ${port}`);
    });
  } catch (error) {
    console.error("Error in bootstrap:", error);
    process.exit(1);
  }
};

// run bootstrap
bootstrap().catch((error) => {
  console.error("Error in bootstrap:", error);
  process.exit(1);
});
