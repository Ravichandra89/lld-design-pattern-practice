import { Pool } from "pg";
import dotenv from "dotenv";

dotenv.config();

// create the pool
const pool = new Pool({
  user: process.env.DB_USER,
  host: process.env.DB_HOST,
  database: process.env.DB_NAME,
  password: process.env.DB_PASSWORD,
  port: Number(process.env.DB_PORT),
});

export const initilizeDb = async () => {
  try {
    await pool.query(`
            CREATE TABLE IF NOT EXISTS orders (
                order_id TEXT PRIMARY KEY,
                user_id INTEGER,
                product_id INTEGER,
                price INTEGER,
                status TEXT,
                created_at TIMESTAMP Default now()
            );
        `);
  } catch (error) {
    console.error("Error initializing database:", error);
    throw error;
  }
};
