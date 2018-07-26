import * as $protobuf from "protobufjs";

/** Properties of a Void. */
export interface IVoid {
}

/** Represents a Void. */
export class Void implements IVoid {

    /**
     * Constructs a new Void.
     * @param [properties] Properties to set
     */
    constructor(properties?: IVoid);

    /**
     * Creates a new Void instance using the specified properties.
     * @param [properties] Properties to set
     * @returns Void instance
     */
    public static create(properties?: IVoid): Void;

    /**
     * Encodes the specified Void message. Does not implicitly {@link Void.verify|verify} messages.
     * @param message Void message or plain object to encode
     * @param [writer] Writer to encode to
     * @returns Writer
     */
    public static encode(message: IVoid, writer?: $protobuf.Writer): $protobuf.Writer;

    /**
     * Encodes the specified Void message, length delimited. Does not implicitly {@link Void.verify|verify} messages.
     * @param message Void message or plain object to encode
     * @param [writer] Writer to encode to
     * @returns Writer
     */
    public static encodeDelimited(message: IVoid, writer?: $protobuf.Writer): $protobuf.Writer;

    /**
     * Decodes a Void message from the specified reader or buffer.
     * @param reader Reader or buffer to decode from
     * @param [length] Message length if known beforehand
     * @returns Void
     * @throws {Error} If the payload is not a reader or valid buffer
     * @throws {$protobuf.util.ProtocolError} If required fields are missing
     */
    public static decode(reader: ($protobuf.Reader|Uint8Array), length?: number): Void;

    /**
     * Decodes a Void message from the specified reader or buffer, length delimited.
     * @param reader Reader or buffer to decode from
     * @returns Void
     * @throws {Error} If the payload is not a reader or valid buffer
     * @throws {$protobuf.util.ProtocolError} If required fields are missing
     */
    public static decodeDelimited(reader: ($protobuf.Reader|Uint8Array)): Void;

    /**
     * Verifies a Void message.
     * @param message Plain object to verify
     * @returns `null` if valid, otherwise the reason why it is not
     */
    public static verify(message: { [k: string]: any }): (string|null);

    /**
     * Creates a Void message from a plain object. Also converts values to their respective internal types.
     * @param object Plain object
     * @returns Void
     */
    public static fromObject(object: { [k: string]: any }): Void;

    /**
     * Creates a plain object from a Void message. Also converts values to other types if specified.
     * @param message Void
     * @param [options] Conversion options
     * @returns Plain object
     */
    public static toObject(message: Void, options?: $protobuf.IConversionOptions): { [k: string]: any };

    /**
     * Converts this Void to JSON.
     * @returns JSON object
     */
    public toJSON(): { [k: string]: any };
}

/** Properties of a BoolResult. */
export interface IBoolResult {

    /** BoolResult result */
    result?: (boolean|null);
}

/** Represents a BoolResult. */
export class BoolResult implements IBoolResult {

    /**
     * Constructs a new BoolResult.
     * @param [properties] Properties to set
     */
    constructor(properties?: IBoolResult);

    /** BoolResult result. */
    public result: boolean;

    /**
     * Creates a new BoolResult instance using the specified properties.
     * @param [properties] Properties to set
     * @returns BoolResult instance
     */
    public static create(properties?: IBoolResult): BoolResult;

    /**
     * Encodes the specified BoolResult message. Does not implicitly {@link BoolResult.verify|verify} messages.
     * @param message BoolResult message or plain object to encode
     * @param [writer] Writer to encode to
     * @returns Writer
     */
    public static encode(message: IBoolResult, writer?: $protobuf.Writer): $protobuf.Writer;

    /**
     * Encodes the specified BoolResult message, length delimited. Does not implicitly {@link BoolResult.verify|verify} messages.
     * @param message BoolResult message or plain object to encode
     * @param [writer] Writer to encode to
     * @returns Writer
     */
    public static encodeDelimited(message: IBoolResult, writer?: $protobuf.Writer): $protobuf.Writer;

    /**
     * Decodes a BoolResult message from the specified reader or buffer.
     * @param reader Reader or buffer to decode from
     * @param [length] Message length if known beforehand
     * @returns BoolResult
     * @throws {Error} If the payload is not a reader or valid buffer
     * @throws {$protobuf.util.ProtocolError} If required fields are missing
     */
    public static decode(reader: ($protobuf.Reader|Uint8Array), length?: number): BoolResult;

    /**
     * Decodes a BoolResult message from the specified reader or buffer, length delimited.
     * @param reader Reader or buffer to decode from
     * @returns BoolResult
     * @throws {Error} If the payload is not a reader or valid buffer
     * @throws {$protobuf.util.ProtocolError} If required fields are missing
     */
    public static decodeDelimited(reader: ($protobuf.Reader|Uint8Array)): BoolResult;

    /**
     * Verifies a BoolResult message.
     * @param message Plain object to verify
     * @returns `null` if valid, otherwise the reason why it is not
     */
    public static verify(message: { [k: string]: any }): (string|null);

    /**
     * Creates a BoolResult message from a plain object. Also converts values to their respective internal types.
     * @param object Plain object
     * @returns BoolResult
     */
    public static fromObject(object: { [k: string]: any }): BoolResult;

    /**
     * Creates a plain object from a BoolResult message. Also converts values to other types if specified.
     * @param message BoolResult
     * @param [options] Conversion options
     * @returns Plain object
     */
    public static toObject(message: BoolResult, options?: $protobuf.IConversionOptions): { [k: string]: any };

    /**
     * Converts this BoolResult to JSON.
     * @returns JSON object
     */
    public toJSON(): { [k: string]: any };
}

/** Properties of a SummonerName. */
export interface ISummonerName {

    /** SummonerName name */
    name?: (string|null);
}

/** Represents a SummonerName. */
export class SummonerName implements ISummonerName {

    /**
     * Constructs a new SummonerName.
     * @param [properties] Properties to set
     */
    constructor(properties?: ISummonerName);

    /** SummonerName name. */
    public name: string;

    /**
     * Creates a new SummonerName instance using the specified properties.
     * @param [properties] Properties to set
     * @returns SummonerName instance
     */
    public static create(properties?: ISummonerName): SummonerName;

    /**
     * Encodes the specified SummonerName message. Does not implicitly {@link SummonerName.verify|verify} messages.
     * @param message SummonerName message or plain object to encode
     * @param [writer] Writer to encode to
     * @returns Writer
     */
    public static encode(message: ISummonerName, writer?: $protobuf.Writer): $protobuf.Writer;

    /**
     * Encodes the specified SummonerName message, length delimited. Does not implicitly {@link SummonerName.verify|verify} messages.
     * @param message SummonerName message or plain object to encode
     * @param [writer] Writer to encode to
     * @returns Writer
     */
    public static encodeDelimited(message: ISummonerName, writer?: $protobuf.Writer): $protobuf.Writer;

    /**
     * Decodes a SummonerName message from the specified reader or buffer.
     * @param reader Reader or buffer to decode from
     * @param [length] Message length if known beforehand
     * @returns SummonerName
     * @throws {Error} If the payload is not a reader or valid buffer
     * @throws {$protobuf.util.ProtocolError} If required fields are missing
     */
    public static decode(reader: ($protobuf.Reader|Uint8Array), length?: number): SummonerName;

    /**
     * Decodes a SummonerName message from the specified reader or buffer, length delimited.
     * @param reader Reader or buffer to decode from
     * @returns SummonerName
     * @throws {Error} If the payload is not a reader or valid buffer
     * @throws {$protobuf.util.ProtocolError} If required fields are missing
     */
    public static decodeDelimited(reader: ($protobuf.Reader|Uint8Array)): SummonerName;

    /**
     * Verifies a SummonerName message.
     * @param message Plain object to verify
     * @returns `null` if valid, otherwise the reason why it is not
     */
    public static verify(message: { [k: string]: any }): (string|null);

    /**
     * Creates a SummonerName message from a plain object. Also converts values to their respective internal types.
     * @param object Plain object
     * @returns SummonerName
     */
    public static fromObject(object: { [k: string]: any }): SummonerName;

    /**
     * Creates a plain object from a SummonerName message. Also converts values to other types if specified.
     * @param message SummonerName
     * @param [options] Conversion options
     * @returns Plain object
     */
    public static toObject(message: SummonerName, options?: $protobuf.IConversionOptions): { [k: string]: any };

    /**
     * Converts this SummonerName to JSON.
     * @returns JSON object
     */
    public toJSON(): { [k: string]: any };
}

/** Properties of a CurrentGame. */
export interface ICurrentGame {

    /** CurrentGame val */
    val?: (string|null);
}

/** Represents a CurrentGame. */
export class CurrentGame implements ICurrentGame {

    /**
     * Constructs a new CurrentGame.
     * @param [properties] Properties to set
     */
    constructor(properties?: ICurrentGame);

    /** CurrentGame val. */
    public val: string;

    /**
     * Creates a new CurrentGame instance using the specified properties.
     * @param [properties] Properties to set
     * @returns CurrentGame instance
     */
    public static create(properties?: ICurrentGame): CurrentGame;

    /**
     * Encodes the specified CurrentGame message. Does not implicitly {@link CurrentGame.verify|verify} messages.
     * @param message CurrentGame message or plain object to encode
     * @param [writer] Writer to encode to
     * @returns Writer
     */
    public static encode(message: ICurrentGame, writer?: $protobuf.Writer): $protobuf.Writer;

    /**
     * Encodes the specified CurrentGame message, length delimited. Does not implicitly {@link CurrentGame.verify|verify} messages.
     * @param message CurrentGame message or plain object to encode
     * @param [writer] Writer to encode to
     * @returns Writer
     */
    public static encodeDelimited(message: ICurrentGame, writer?: $protobuf.Writer): $protobuf.Writer;

    /**
     * Decodes a CurrentGame message from the specified reader or buffer.
     * @param reader Reader or buffer to decode from
     * @param [length] Message length if known beforehand
     * @returns CurrentGame
     * @throws {Error} If the payload is not a reader or valid buffer
     * @throws {$protobuf.util.ProtocolError} If required fields are missing
     */
    public static decode(reader: ($protobuf.Reader|Uint8Array), length?: number): CurrentGame;

    /**
     * Decodes a CurrentGame message from the specified reader or buffer, length delimited.
     * @param reader Reader or buffer to decode from
     * @returns CurrentGame
     * @throws {Error} If the payload is not a reader or valid buffer
     * @throws {$protobuf.util.ProtocolError} If required fields are missing
     */
    public static decodeDelimited(reader: ($protobuf.Reader|Uint8Array)): CurrentGame;

    /**
     * Verifies a CurrentGame message.
     * @param message Plain object to verify
     * @returns `null` if valid, otherwise the reason why it is not
     */
    public static verify(message: { [k: string]: any }): (string|null);

    /**
     * Creates a CurrentGame message from a plain object. Also converts values to their respective internal types.
     * @param object Plain object
     * @returns CurrentGame
     */
    public static fromObject(object: { [k: string]: any }): CurrentGame;

    /**
     * Creates a plain object from a CurrentGame message. Also converts values to other types if specified.
     * @param message CurrentGame
     * @param [options] Conversion options
     * @returns Plain object
     */
    public static toObject(message: CurrentGame, options?: $protobuf.IConversionOptions): { [k: string]: any };

    /**
     * Converts this CurrentGame to JSON.
     * @returns JSON object
     */
    public toJSON(): { [k: string]: any };
}

/** Represents a DtoGService */
export class DtoGService extends $protobuf.rpc.Service {

    /**
     * Constructs a new DtoGService service.
     * @param rpcImpl RPC implementation
     * @param [requestDelimited=false] Whether requests are length-delimited
     * @param [responseDelimited=false] Whether responses are length-delimited
     */
    constructor(rpcImpl: $protobuf.RPCImpl, requestDelimited?: boolean, responseDelimited?: boolean);

    /**
     * Creates new DtoGService service using the specified rpc implementation.
     * @param rpcImpl RPC implementation
     * @param [requestDelimited=false] Whether requests are length-delimited
     * @param [responseDelimited=false] Whether responses are length-delimited
     * @returns RPC service. Useful where requests and/or responses are streamed.
     */
    public static create(rpcImpl: $protobuf.RPCImpl, requestDelimited?: boolean, responseDelimited?: boolean): DtoGService;

    /**
     * Calls RegisterUser.
     * @param request SummonerName message or plain object
     * @param callback Node-style callback called with the error, if any, and BoolResult
     */
    public registerUser(request: ISummonerName, callback: DtoGService.RegisterUserCallback): void;

    /**
     * Calls RegisterUser.
     * @param request SummonerName message or plain object
     * @returns Promise
     */
    public registerUser(request: ISummonerName): Promise<BoolResult>;

    /**
     * Calls GetCurrentGame.
     * @param request SummonerName message or plain object
     * @param callback Node-style callback called with the error, if any, and CurrentGame
     */
    public getCurrentGame(request: ISummonerName, callback: DtoGService.GetCurrentGameCallback): void;

    /**
     * Calls GetCurrentGame.
     * @param request SummonerName message or plain object
     * @returns Promise
     */
    public getCurrentGame(request: ISummonerName): Promise<CurrentGame>;
}

export namespace DtoGService {

    /**
     * Callback as used by {@link DtoGService#registerUser}.
     * @param error Error, if any
     * @param [response] BoolResult
     */
    type RegisterUserCallback = (error: (Error|null), response?: BoolResult) => void;

    /**
     * Callback as used by {@link DtoGService#getCurrentGame}.
     * @param error Error, if any
     * @param [response] CurrentGame
     */
    type GetCurrentGameCallback = (error: (Error|null), response?: CurrentGame) => void;
}
