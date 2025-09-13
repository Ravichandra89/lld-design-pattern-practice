import express from "express";
import dotenv from "dotenv";

dotenv.config();

// create express server
const app = express();
app.use(express.json());
app.use(express.urlencoded({ extended: true}));

const PORT = process.env.PORT || 5000;

app.listen(PORT, () => {
    console.log(`Order Service running on port ${PORT}`);
})