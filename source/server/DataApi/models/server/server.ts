﻿import * as path from "path";
import * as http from "http";

import * as debug from "debug";
import * as express from "express";

export class Server {
    private readonly app: express.Express;
    private server: http.Server;

    constructor(port: number, routes: Map<string, express.Router>) {
        const app = this.app = express();

        // view engine setup
        app.set("views", path.join(__dirname, "..", "..", "views"));
        app.set("view engine", "ejs");

        app.use(express.static(path.join(__dirname, "..", "..", "public")));

        routes.forEach((route, rootPath) => {
            app.use(rootPath, route);
        });

        // catch 404 and forward to error handler
        app.use((req, res, next) => {
            const err = new Error("Not Found");
            err["status"] = 404;
            next(err);
        });

        // error handlers

        // development error handler
        // will print stacktrace
        if (app.get("env") === "development") {
            app.use((err: any, req: express.Request, res: express.Response, next) => {
                res.status(err["status"] || 500);
                res.render("error", {
                    message: err.message,
                    error: err
                });
            });
        }

        // production error handler
        // no stacktraces leaked to user
        app.use((err: any, req: express.Request, res: express.Response, next) => {
            res.status(err.status || 500);
            res.render("error", {
                message: err.message,
                error: {}
            });
        });

        app.set("port", port);
    }

    run() {
        this.server = this.app.listen(this.app.get("port"), () => {
            debug(`Express server listening on port ${this.server.address().port}`);
        });
    }
}