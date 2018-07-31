import { BrowserModule } from "@angular/platform-browser";
import { NgModule } from "@angular/core";
import { FormsModule } from "@angular/forms";
import { RouterModule, Routes } from "@angular/router";

import { NgbModule } from "@ng-bootstrap/ng-bootstrap"

import { AppComponent } from "./component/src/app.component";
import { ErrorComponent } from "./component/src/error.component";
import { HeaderComponent } from "./component/src/header.component";
import { IndexComponent } from "./component/src/index.component";
import { LeftMenuComponent } from "./component/src/left-menu.component";
import { SummonerComponent } from "./component/src/summoner.component";

const routes = [
    {
        path: "",
        component: IndexComponent
    },
    {
        path: "summoner/:name",
        component: SummonerComponent
    },
    {
        path: "error",
        component: ErrorComponent,
    },
    {
        path: "**",
        redirectTo: "error"
    }
] as Routes;

@NgModule({
    declarations: [
        AppComponent,
        ErrorComponent,
        HeaderComponent,
        IndexComponent,
        LeftMenuComponent,
        SummonerComponent
    ],
    imports: [
        BrowserModule,
        FormsModule,
        NgbModule.forRoot(),
        RouterModule.forRoot(routes)
    ],
    providers: [],
    bootstrap: [AppComponent]
})
export class AppModule {
}
