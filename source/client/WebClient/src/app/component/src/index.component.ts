import { Component } from "@angular/core";
import { Router } from "@angular/router";

import { DataApiService } from "../../service/data-api.service";

import { ResultStruct } from "../../util/struct";

@Component({
    selector: "app-index",
    templateUrl: "../template/index.component.html",
    styleUrls: ["../css/index.component.css"]
})
export class IndexComponent {
    constructor(private readonly router: Router, private readonly dataApiService: DataApiService) {

    }

    onSearchSummoner(summonerName: string) {
        this.dataApiService.register(summonerName)
            .then((jsonVal: ResultStruct) => {
                if (jsonVal.result === 1) {
                    this.router.navigate(["/summoner", summonerName]);
                } else {
                    this.router.navigate(["/error"]);
                }
            })
            .catch(reason => {
                console.error(reason);
            });
    }
}
