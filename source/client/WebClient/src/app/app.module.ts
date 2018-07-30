import { BrowserModule } from "@angular/platform-browser";
import { NgModule } from "@angular/core";
import { RouterModule, Routes } from "@angular/router";

import { NgbModule } from "@ng-bootstrap/ng-bootstrap"

import { AppComponent } from "./component/src/app.component";
import { HeaderComponent } from "./component/src/header.component";
import { IndexComponent } from "./component/src/index.component";
import { LeftMenuComponent } from "./component/src/left-menu.component";

const routes = [
    {
        path: "",
        component: IndexComponent
    }
] as Routes;

@NgModule({
    declarations: [
        AppComponent,
        HeaderComponent,
        IndexComponent,
        LeftMenuComponent
    ],
    imports: [
        BrowserModule,
        NgbModule.forRoot(),
        RouterModule.forRoot(routes)
    ],
    providers: [],
    bootstrap: [AppComponent]
})
export class AppModule {
}
