import * as path from "path";
import * as fs from "fs";

import * as ejs from "ejs";

import "../../data/api/api_type";

function generate() {
    const enums = [] as string[];

    for (const key in RiotApi.ApiType) {
        enums.push(key);
    }
}