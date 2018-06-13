import * as fs from "fs";
import * as path from "path";

import { pbjs, pbts } from "protobufjs/cli";

function generate() {
    const files = fs.readdirSync(path.join(__dirname, "..", "..", "data", "proto"));
    const allProtos = files.join(" ");
}