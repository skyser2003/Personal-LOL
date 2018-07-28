import { BrowserModule } from "@angular/platform-browser";
import { NgModule } from "@angular/core";

import { NgbModule } from "@ng-bootstrap/ng-bootstrap"

import { AppComponent } from "./component/src/app.component";
import { HeaderComponent } from "./component/src/header.component";
import { LeftMenuComponent } from "./component/src/left-menu.component";

@NgModule({
  declarations: [
      AppComponent,
      HeaderComponent,
      LeftMenuComponent
  ],
  imports: [
      BrowserModule,
      NgbModule.forRoot()
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
