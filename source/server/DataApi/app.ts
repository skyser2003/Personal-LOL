import * as path from "path";

import * as debug from "debug";
import * as express from "express";

import routes from "./routes/index";
import api from "./routes/api";

import { Server } from "./models/server/server";

class Main {
    private readonly server:Server;

    constructor() {
        this.server = new Server(parseInt(process.env.PORT) || 3000,
            new Map([
                ["/", routes],
                ["/api", api]
            ])
        );
    }

    run() {
        this.server.run();
    }
}

const main = new Main();
main.run();