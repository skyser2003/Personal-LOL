import * as fs from "fs";
import * as path from "path";

import { pbjs, pbts } from "protobufjs/cli";

const protoRegex = /^(.*)\.proto$/;

function generate(filename: string) {
    return new Promise((resolve, reject) => {
        const args: string[] = [];

        const match = protoRegex.exec(filename);
        if (match) {
            const serviceName = match[1];
            args.push("-r", serviceName);
        }

        args.push("-t", "static-module", "-w", "commonjs", "-o", `generated/${filename}.generated.js`);
        args.push(`./proto/${filename}.proto`);

        pbjs.main(args,
            (err, output) => {
                if (err) {
                    reject(err);
                } else {
                    pbts.main(["-o", `generated/${filename}.generated.d.ts`, `generated/${filename}.generated.js`],
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

function generateAll() {
    const files = fs.readdirSync(path.join(__dirname, "..", "..", "data", "proto"));

    const protoFiles: string[] = [];

    files.forEach(filename => {

    });
}