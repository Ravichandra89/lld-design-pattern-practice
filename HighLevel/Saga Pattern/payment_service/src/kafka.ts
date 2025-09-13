import { Kafka, Producer, Consumer } from "kafkajs";

const kafka = new Kafka({
  clientId: "payment-service",
  brokers: [process.env.KAFKA_BROKER || "localhost:9092"],
});

export const producer: Producer = kafka.producer();

export const createConsumer = (groupId: string) => {
  return kafka.consumer({ groupId });
};

export const runProducer = async () => {
  await producer.connect();
};
