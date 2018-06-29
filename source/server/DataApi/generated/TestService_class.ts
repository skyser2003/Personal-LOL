import * as packet from "./packet.generated";
import { TestService_Interface } from "./TestService_interface";
export { TestService_Interface } from "./TestService_interface";

export class TestService {
    constructor(private readonly serviceInterface: TestService_Interface) {
    }


    testSend(request: packet.ITestMessage) {
        return new Promise<packet.IVoid>((resolve, reject) => {
            this.serviceInterface.testSend(request, (err, response) => {
                if (err) {
                    reject(err);
                    return;
                }

                resolve(response);
            });
        });
    }

}