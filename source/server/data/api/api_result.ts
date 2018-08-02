export namespace RiotApi {
    class BannedChampions {
        pickTurn: number;
        championId: number;
        teamId: number;
    }

    class Observer {
        encryptionKey: string;
    }

    class GameCustomizationObject {
        category: string;
        content: string;
    }

    class Perks {
        perkStyle: number;
        perkIds: number[];
        perkSubStyle: number;
    }

    class CurrentGameParticipant {
        profileIconId: number;
        championId: number;
        summonerName: string;
        gameCustomizationObject: GameCustomizationObject[];
        bot: boolean;
        perks: Perks;
        spell1d: number;
        spell2ld: number;
        teamId: number;
        summonerId: number;
    }

    class MatchReferenceDto {
        lane: string;
        gameId: number;
        champion: number;
        platformId: string;
        season: number;
        queue: number;
        role: string;
        timestamp: number;
    }
}