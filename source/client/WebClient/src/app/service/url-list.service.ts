import { Injectable } from "@angular/core";

@Injectable({
    providedIn: "root"
})
export class UrlListService {
    constructor(public readonly urls: string[]) {
        for (let i = 0; i < urls.length; ++i) {
            const url = urls[i];
            if (url.endsWith("/")) {
                urls[i] = url.slice(0, -1);
            }
        }
    }
}
