import { createConsumer } from "../kafka";
import { pool } from "../db";

export const startPaymentConsumer = async () => {
  const consumer = createConsumer("order-service-group");
  await consumer.connect();
  // subscribe to the topic
  await consumer.subscribe({
    topic: "payment-events",
    fromBeginning: true,
  });

  await consumer.run({
    eachMessage: async ({ message }) => {
      if (!message.value) return;
      // prepare the payload for updating the order status
      const payload = JSON.parse(message.value.toString());
      const { orderId, status } = payload;
      console.log("[OrderService] Received payment-event:", payload);

      const newStatus = status === "SUCCESS" ? "COMPLETED" : "CANCELLED";

      await pool.query(`UPDATE orders SET status = $2 WHERE order_id = $1`, [
        orderId,
        newStatus,
      ]);
      console.log(
        `[OrderService] Order ${orderId} status updated to ${newStatus}`
      );
    },
  });
};
