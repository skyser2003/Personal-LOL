import { Component } from "@angular/core";
import { Router } from "@angular/router";

@Component({
    selector: "app-index",
    templateUrl: "../template/index.component.html",
    styleUrls: ["../css/index.component.css"]
})
export class IndexComponent {
    constructor(private readonly router: Router) {

    }

    onSearchSummoner(summonerName: string) {
        const req = new Request("http://localhost:3000/register", { method: "POST", body: JSON.stringify({ summoner_name: summonerName }) });
        fetch(req)
            .then(res => res.json())
            .then(jsonVal => {
                this.router.navigate(["/summoner", summonerName]);
            })
            .catch(reason => {
                console.error(reason);
            });
    }
}
