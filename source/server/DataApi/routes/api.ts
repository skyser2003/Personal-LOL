import * as path from "path";

import * as express from "express";
import * as grpc from "grpc";

import * as packet from "../generated/packet.generated";

const packetList = grpc.load(path.join(__dirname, "..", "..", "data", "proto", "packet.proto"));
const TestService = packetList["TestService"] as typeof grpc.Client;
const client = new TestService("localhost:9999", grpc.credentials.createInsecure());

const testClient = (client as object) as packet.TestService;

const router = express.Router();

router.get("/", (req, res) => {
    testClient.testSend({ x: 1 },
        (err, res) => {
            console.error(err);
        });

    res.render("index", { title: "Express" });
});

export default router;