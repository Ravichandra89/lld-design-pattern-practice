import { Kafka, Producer, Consumer } from "kafkajs";

const kafka = new Kafka({
  clientId: "order-service",
  brokers: [process.env.KAFKA_BROKER || "localhost:9092"],
});

// create producer

export const producer: Producer = kafka.producer();

export const createProducer = async () => {
  await producer.connect();
};

export const createConsumer = (groupId: string): Consumer => {
  return kafka.consumer({
    groupId,
  });
};
