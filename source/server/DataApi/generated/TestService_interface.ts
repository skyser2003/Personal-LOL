import * as grpc from "grpc";

import * as packet from "./packet.generated";

export interface TestService_Interface extends grpc.Client {

    testSend(request: packet.ITestMessage, callback?: (error: Error, response: packet.IVoid) => void);

}