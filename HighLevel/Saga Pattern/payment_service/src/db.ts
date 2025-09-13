import { Pool } from "pg";
import dotenv from "dotenv";

dotenv.config();

export const pool = new Pool({
  host: process.env.DB_HOST,
  port: Number(process.env.DB_PORT),
  user: process.env.DB_USER,
  password: process.env.DB_PASSWORD,
  database: process.env.DB_NAME,
});

export const initilizePaymentTable = async () => {
  try {
    await pool.query(`
    CREATE TABLE IF NOT EXISTS payments (
      payment_id SERIAL PRIMARY KEY,
      order_id TEXT,
      user_id INTEGER,
      product_id INTEGER,
      price INTEGER,
      payment_status TEXT,
      created_at TIMESTAMP DEFAULT now()
    );
  `);
  } catch (error) {
    console.error("Error creating payment table:", error);
    throw error;
  }
};
