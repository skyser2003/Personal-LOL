import * as grpc from "grpc";

import * as packet from "./packet.generated";

export interface DtoGService_Interface extends grpc.Client {

    registerUser(request: packet.ISummonerName, callback?: (error: Error, response: packet.IBoolResult) => void);

    getCurrentGame(request: packet.ISummonerName, callback?: (error: Error, response: packet.IBoolResult) => void);

}