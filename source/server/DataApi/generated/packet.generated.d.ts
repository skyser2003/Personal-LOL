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

/** Properties of a TestMessage. */
export interface ITestMessage {

    /** TestMessage x */
    x?: (number|null);
}

/** Represents a TestMessage. */
export class TestMessage implements ITestMessage {

    /**
     * Constructs a new TestMessage.
     * @param [properties] Properties to set
     */
    constructor(properties?: ITestMessage);

    /** TestMessage x. */
    public x: number;

    /**
     * Creates a new TestMessage instance using the specified properties.
     * @param [properties] Properties to set
     * @returns TestMessage instance
     */
    public static create(properties?: ITestMessage): TestMessage;

    /**
     * Encodes the specified TestMessage message. Does not implicitly {@link TestMessage.verify|verify} messages.
     * @param message TestMessage message or plain object to encode
     * @param [writer] Writer to encode to
     * @returns Writer
     */
    public static encode(message: ITestMessage, writer?: $protobuf.Writer): $protobuf.Writer;

    /**
     * Encodes the specified TestMessage message, length delimited. Does not implicitly {@link TestMessage.verify|verify} messages.
     * @param message TestMessage message or plain object to encode
     * @param [writer] Writer to encode to
     * @returns Writer
     */
    public static encodeDelimited(message: ITestMessage, writer?: $protobuf.Writer): $protobuf.Writer;

    /**
     * Decodes a TestMessage message from the specified reader or buffer.
     * @param reader Reader or buffer to decode from
     * @param [length] Message length if known beforehand
     * @returns TestMessage
     * @throws {Error} If the payload is not a reader or valid buffer
     * @throws {$protobuf.util.ProtocolError} If required fields are missing
     */
    public static decode(reader: ($protobuf.Reader|Uint8Array), length?: number): TestMessage;

    /**
     * Decodes a TestMessage message from the specified reader or buffer, length delimited.
     * @param reader Reader or buffer to decode from
     * @returns TestMessage
     * @throws {Error} If the payload is not a reader or valid buffer
     * @throws {$protobuf.util.ProtocolError} If required fields are missing
     */
    public static decodeDelimited(reader: ($protobuf.Reader|Uint8Array)): TestMessage;

    /**
     * Verifies a TestMessage message.
     * @param message Plain object to verify
     * @returns `null` if valid, otherwise the reason why it is not
     */
    public static verify(message: { [k: string]: any }): (string|null);

    /**
     * Creates a TestMessage message from a plain object. Also converts values to their respective internal types.
     * @param object Plain object
     * @returns TestMessage
     */
    public static fromObject(object: { [k: string]: any }): TestMessage;

    /**
     * Creates a plain object from a TestMessage message. Also converts values to other types if specified.
     * @param message TestMessage
     * @param [options] Conversion options
     * @returns Plain object
     */
    public static toObject(message: TestMessage, options?: $protobuf.IConversionOptions): { [k: string]: any };

    /**
     * Converts this TestMessage to JSON.
     * @returns JSON object
     */
    public toJSON(): { [k: string]: any };
}

/** Represents a TestService */
export class TestService extends $protobuf.rpc.Service {

    /**
     * Constructs a new TestService service.
     * @param rpcImpl RPC implementation
     * @param [requestDelimited=false] Whether requests are length-delimited
     * @param [responseDelimited=false] Whether responses are length-delimited
     */
    constructor(rpcImpl: $protobuf.RPCImpl, requestDelimited?: boolean, responseDelimited?: boolean);

    /**
     * Creates new TestService service using the specified rpc implementation.
     * @param rpcImpl RPC implementation
     * @param [requestDelimited=false] Whether requests are length-delimited
     * @param [responseDelimited=false] Whether responses are length-delimited
     * @returns RPC service. Useful where requests and/or responses are streamed.
     */
    public static create(rpcImpl: $protobuf.RPCImpl, requestDelimited?: boolean, responseDelimited?: boolean): TestService;

    /**
     * Calls TestSend.
     * @param request TestMessage message or plain object
     * @param callback Node-style callback called with the error, if any, and Void
     */
    public testSend(request: ITestMessage, callback: TestService.TestSendCallback): void;

    /**
     * Calls TestSend.
     * @param request TestMessage message or plain object
     * @returns Promise
     */
    public testSend(request: ITestMessage): Promise<Void>;
}

export namespace TestService {

    /**
     * Callback as used by {@link TestService#testSend}.
     * @param error Error, if any
     * @param [response] Void
     */
    type TestSendCallback = (error: (Error|null), response?: Void) => void;
}
