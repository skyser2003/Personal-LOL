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
        this.router.navigate(["/summoner", summonerName]);
    }
}
