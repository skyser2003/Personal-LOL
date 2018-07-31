import { Component } from "@angular/core";
import { Router } from "@angular/router";

import { ResultStruct } from "../../util/struct";

@Component({
    selector: "app-index",
    templateUrl: "../template/index.component.html",
    styleUrls: ["../css/index.component.css"]
})
export class IndexComponent {
    constructor(private readonly router: Router) {

    }

    onSearchSummoner(summonerName: string) {
        const req = new Request("http://localhost:3000/api/register",
            {
                method: "POST",
                body: JSON.stringify({ summoner_name: summonerName }),
                headers: {
                    "Content-Type": "application/json"
                }
            });
        fetch(req)
            .then(res => res.json())
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
