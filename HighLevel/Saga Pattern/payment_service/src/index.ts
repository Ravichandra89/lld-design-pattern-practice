import dotenv from "dotenv";
dotenv.config();

import { initilizePaymentTable } from "./db";
import { startOrderConsumer } from "./consumer/order.consumer";

async function bootstrap() {
  await initilizePaymentTable();
  await startOrderConsumer();
  console.log("Payment service started.");
}

bootstrap().catch((e) => {
  console.error(e);
  process.exit(1);
});
