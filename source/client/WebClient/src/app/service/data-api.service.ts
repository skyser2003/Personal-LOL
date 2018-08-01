import { Injectable, FactoryProvider } from "@angular/core";

@Injectable({
    providedIn: "root",
})
export class DataApiService {
    constructor(private readonly url: string) {

    }
}

export function dataApiServiceFactory(url: string) {

}

// TODO
export const dataApiServiceProvider: FactoryProvider = {
    provide: DataApiService,
    useFactory: dataApiServiceFactory,
    deps: []
};
