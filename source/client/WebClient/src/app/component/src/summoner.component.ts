import { Component } from "@angular/core";
import { Router, ActivatedRoute } from "@angular/router";
import { switchMap } from "rxjs/operators";

@Component({
    selector: "app-summoner",
    templateUrl: "../template/summoner.component.html",
    styleUrls: ["../css/summoner.component.css"]
})
export class SummonerComponent {
    jsonVal: string;
    summonerName: string;

    constructor(private readonly router: Router, private readonly route: ActivatedRoute) {
    }

    ngOnInit() {
        this.jsonVal = this.route.snapshot.params["name"] as string;
1    }
}
