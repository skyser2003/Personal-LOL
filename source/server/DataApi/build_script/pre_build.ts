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

class ServiceInterfaceEjsArgument {
    protoName: string;
    serviceName: string;
    methods: Method[] = [];
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

function generateProto(protoDir: string, protoFiles: string[]) {
    const promises = [] as Promise<{}>[];

    protoFiles.forEach(filename => {
        const match = protoRegex.exec(filename);
        if (match) {
            const protoName = match[1];
            promises.push(generate(protoName));
        }
    });

    return promises;
}

function generateGrpc(protoDir: string, protoFiles: string[]) {
    // Grpc
    const interfaceEjs = path.join(__dirname, "..", "grpc_template", "service_interface.ejs");
    const classEjs = path.join(__dirname, "..", "grpc_template", "service_class.ejs");

    const serviceArgs = [] as ServiceInterfaceEjsArgument[];

    protoFiles.forEach(filename => {
        const match = protoRegex.exec(filename);
        if (match) {
            const protoName = match[1];

            const root = protobuf.loadSync(path.join(protoDir, filename));
            root.nestedArray.forEach(obj => {
                if (obj instanceof protobuf.Service === false) {
                    return;
                }

                const service = obj as protobuf.Service;

                const arg = new ServiceInterfaceEjsArgument();
                arg.protoName = protoName;
                arg.serviceName = obj.name;

                for (const method of service.methodsArray) {
                    const methodInfo = new Method();
                    methodInfo.name = method.name;
                    methodInfo.name = methodInfo.name.replace(/^./, c => c.toLowerCase());
                    methodInfo.requestType = method.requestType;
                    methodInfo.responseType = method.responseType;

                    arg.methods.push(methodInfo);
                }

                serviceArgs.push(arg);
            });
        }
    });

    const renderEjs = (ejsFilename: string, outputFilename: string, arg: ServiceInterfaceEjsArgument) => {
        return new Promise((resolve, reject) => {
            ejs.renderFile(ejsFilename,
                arg,
                (err, result) => {
                    if (err) {
                        console.error(err);
                        reject();
                        return;
                    }

                    fs.writeFile(path.join(__dirname, "..", "generated", `${arg.serviceName}_${outputFilename}`), result, err2 => {
                        if (err2) {
                            console.error(err2);
                            reject();
                            return;
                        }

                        resolve();
                    });
                });
        });
    };

    const promises = [] as Promise<{}>[];

    serviceArgs.forEach(arg => {
        const prom = renderEjs(interfaceEjs, "interface.ts", arg)
            .then(() => {
                return renderEjs(classEjs, "class.ts", arg);
            });
        
        promises.push(prom);
    });

    return promises;
}

async function generateAll() {
    const protoDir = path.join(__dirname, "..", "..", "data", "proto");
    const protoFiles = fs.readdirSync(protoDir);

    const promises = [] as Promise<{}>[];

    promises.push(...generateProto(protoDir, protoFiles));
    promises.push(...generateGrpc(protoDir, protoFiles));

    await Promise.all(promises);
}

generateAll();