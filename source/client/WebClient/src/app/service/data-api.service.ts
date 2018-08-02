import { Injectable, FactoryProvider } from "@angular/core";

import { UrlListService } from "./url-list.service";

@Injectable({
    providedIn: "root"
})
export class DataApiService {
    constructor(private readonly urlListService: UrlListService) {

    }

    register(summonerName: string) {
        const url = this.getRandomUrl();
        const req = new Request(`${url}/api/register`,
            {
                method: "POST",
                body: JSON.stringify({ summoner_name: summonerName }),
                headers: {
                    "Content-Type": "application/json"
                }
            });

        return fetch(req).then(res => res.json());
    }

    getSummonerInfo(summonerName: string) {
        const url = this.getRandomUrl();
        const req = new Request(`${url}/api/summoner/${summonerName}`);

        return fetch(req).then(res => res.json());
    }

    private getRandomUrl() {
        const randIndex = Math.floor(Math.random() * this.urlListService.urls.length);
        return this.urlListService.urls[randIndex];
    }
}

function dataApiServiceFactory(urlListService: UrlListService) {
    return new DataApiService(urlListService);
}

export const dataApiServiceProvider: FactoryProvider = {
    provide: DataApiService,
    useFactory: dataApiServiceFactory,
    deps: [UrlListService]
};
