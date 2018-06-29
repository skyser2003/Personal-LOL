import * as packet from "./packet.generated";
import { DtoGService_Interface } from "./DtoGService_interface";
export { DtoGService_Interface } from "./DtoGService_interface";

export class DtoGService {
    constructor(private readonly serviceInterface: DtoGService_Interface) {
    }


    registerUser(request: packet.ISummonerName) {
        return new Promise<packet.IBoolResult>((resolve, reject) => {
            this.serviceInterface.registerUser(request, (err, response) => {
                if (err) {
                    reject(err);
                    return;
                }

                resolve(response);
            });
        });
    }

}