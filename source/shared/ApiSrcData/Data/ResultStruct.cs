using System.Collections.Generic;

using ApiSrcData.InternalStruct;

namespace ApiSrcData.ResultStruct
{
    // JSON result structs
    public class SUMMONER_SUMMONERS_BY_NAME
    {
        int profileIconId;
        string name;
        long summonerLevel;
        long revisionDate;
        long id;
        long accountId;
    }

    public class SPECTATOR_ACTIVE_GAMES_BY_SUMMONER
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

    public class MATCH_MATCHLISTS_BY_ACCOUNT
    {
        List<MatchReferenceDto> matches;
        int totalGames;
        int startIndex;
        int endIndex;
    }
}