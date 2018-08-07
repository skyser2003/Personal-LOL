using System.Collections.Generic;

namespace ApiSrcGenerator
{
    public class RiotApiStruct
    {
        // Internal structs
        struct BannedChampions
        {
            int pickTurn;
            long championId;
            long teamId;
        }

        struct Observer
        {
            string encryptionKey;
        }

        struct GameCustomizationObject
        {
            string category;
            string content;
        }

        struct Perks
        {
            long perkStyle;
            List<long> perkIds;
            long perkSubStyle;
        }

        struct CurrentGameParticipant
        {
            long profileIconId;
            long championId;
            string summonerName;
            List<GameCustomizationObject> gameCustomizationObject;
            bool bot;
            Perks perks;
            long spell2ld;
            long teamId;
            long spell1d;
            long summonerId;
        }

        struct MatchReferenceDto
        {
            string lane;
            long gameId;
            int champion;
            string platformId;
            int season;
            int queue;
            string role;
            long timestamp;
        }

        // JSON result structs
        class ApiResult_SUMMONER_SUMMONERS_BY_NAME
        {
            int profileIconId;
            string name;
            long summonerLevel;
            long revisionDate;
            long id;
            long accountId;
        }
        
        class ApiResult_SPECTATOR_ACTIVE_GAMES_BY_SUMMONER
        {
            long gameId;
            long gameStartTime;
            string platformId;
            string gameMode;
            long mapId;
            string gameType;
            List<BannedChampions> bannedChampions;
            Observer observer;
            List<CurrentGameParticipant> participants;
            long gameLength;
            long gameQueueConfigId;
        }

        class ApiResult_MATCH_MATCHLISTS_BY_ACCOUNT
        {
            List<MatchReferenceDto> matches;
            int totalGames;
            int startIndex;
            int endIndex;
        }
    }
}