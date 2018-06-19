import * as path from "path";

import * as express from "express";
import * as grpc from "grpc";

import * as packet from "../generated/packet.generated";

const packetList = grpc.load(path.join(__dirname, "..", "..", "data", "proto", "packet.proto"));
const d2gService = packetList["DtoGService"] as typeof grpc.Client;
const client = new d2gService("localhost:9999", grpc.credentials.createInsecure());

const testClient = (client as object) as packet.DtoGService;

const router = express.Router();

router.get("/",
    (req, res) => {
        testClient.registerUser({ name: encodeURI("에펠탑") },
            (err, res) => {
                if (err) {
                    console.error(res);
                }

                console.log(res);
            });

        res.render("index", { title: "Express" });
    });

export default router;