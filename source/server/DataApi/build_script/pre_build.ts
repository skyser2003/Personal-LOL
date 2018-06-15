import * as fs from "fs";
import * as path from "path";

import { pbjs, pbts } from "protobufjs/cli";

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
    const files = fs.readdirSync(path.join(__dirname, "..", "..", "data", "proto"));

    const promises: Promise<{}>[] = [];

    files.forEach(filename => {
        const match = protoRegex.exec(filename);
        if (match) {
            const protoName = match[1];
            promises.push(generate(protoName));
        }
    });

    await Promise.all(promises);
}

generateAll();