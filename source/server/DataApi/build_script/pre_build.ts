import * as fs from "fs";
import * as path from "path";

import * as ejs from "ejs";
import * as protobuf from "protobufjs";

import { pbjs, pbts } from "protobufjs/cli";

class Method {
    name: string;
    requestType: string;
    responseType: string;
}

const protoRegex = /^(.*)\.proto$/;

function generate(protoName: string) {
    return new Promise((resolve, reject) => {
        const args: string[] = [];

        args.push("-r", protoName);
        args.push("-t", "static-module", "-w", "commonjs", "-o", `generated/${protoName}.generated.js`);
        args.push(`../data/proto/${protoName}.proto`);

        pbjs.main(args,
            (err, output) => {
                if (err) {
                    reject(err);
                } else {
                    pbts.main(["-o", `generated/${protoName}.generated.d.ts`, `generated/${protoName}.generated.js`],
                        (err2, output2) => {
                            if (err2) {
                                reject(err);
                            } else {
                                resolve();
                            }

                            return 0;
                        });
                }

                return 0;
            });
    });
}

async function generateAll() {
    const protoDir = path.join(__dirname, "..", "..", "data", "proto");
    const files = fs.readdirSync(protoDir);

    const promises: Promise<{}>[] = [];

    files.forEach(filename => {
        const match = protoRegex.exec(filename);
        if (match) {
            const protoName = match[1];
            promises.push(generate(protoName));
        }
    });

    // Grpc
    const serviceEjsFile = path.join(__dirname, "..", "grpc_template", "service_interface.ejs");

    files.forEach(filename => {
        const match = protoRegex.exec(filename);
        if (match) {
            const protoName = match[1];

            const root = protobuf.loadSync(path.join(protoDir, protoName));
            root.deferred
        }
    });


    ejs.renderFile(serviceEjsFile,
        null,
        (err, result) => {
            if (err) {
                console.error(err);
                return;
            }
        });

    await Promise.all(promises);
}

generateAll();