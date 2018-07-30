import routes from "./routes/index";
import api from "./routes/api";

import { Server } from "./models/server/server";

class Main {
    private readonly server: Server;

    constructor() {
        this.server = new Server(parseInt(process.env.PORT) || 3000,
            new Map([
                ["/", routes],
                ["/api", api]
            ]),
            { allowCrossOrigin: true }
        );
    }

    run() {
        this.server.run();
    }
}

const main = new Main();
main.run();