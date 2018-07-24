import * as path from "path";

import * as express from "express";
import * as grpc from "grpc";

import { DtoGService, DtoGService_Interface } from "../generated/DtoGService_class";

import { ResultStruct } from "../models/util/struct";

const packetList = grpc.load(path.join(__dirname, "..", "..", "data", "proto", "packet.proto"));
const d2gService = packetList["DtoGService"] as typeof grpc.Client;
const client = new d2gService("localhost:9999", grpc.credentials.createInsecure());

const testClient = new DtoGService(client as DtoGService_Interface);

const router = express.Router();

router.post("/register",
    async (req, res) => {
        const ret = new ResultStruct(0);

        const summonerName = req.body.summoner_name;

        try {
            const result = await testClient.registerUser({ name: summonerName });
            ret.result = result.result ? 1 : 0;
        } catch (err) {
            console.error(err);
        }

        res.send(ret);
    });

router.get("/live/:summonerName",
    async (req, res) => {
        const ret = new ResultStruct(0);

        const summonerName = req.params.summonerName;

        try {
            const result = await testClient.getCurrentGame({ name: summonerName });
            ret.result = result.result ? 1 : 0;
        } catch (err) {
            console.error(err);
        }

        res.send(ret);
    });

export default router;