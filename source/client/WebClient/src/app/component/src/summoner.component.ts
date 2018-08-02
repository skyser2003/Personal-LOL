import { Component } from "@angular/core";
import { Router, ActivatedRoute } from "@angular/router";

import { DataApiService } from "../../service/data-api.service";

@Component({
    selector: "app-summoner",
    templateUrl: "../template/summoner.component.html",
    styleUrls: ["../css/summoner.component.css"]
})
export class SummonerComponent {
    jsonVal: string;
    summonerName: string;

    constructor(private readonly router: Router, private readonly route: ActivatedRoute, private readonly dataApiService: DataApiService) {
    }

    async ngOnInit() {
        const summonerName = this.route.snapshot.params["name"] as string;

        const info = await this.dataApiService.getSummonerInfo(summonerName);

        this.jsonVal = JSON.stringify(info);
    }
}
