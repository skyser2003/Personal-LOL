using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ApiSrcGenerator.InternalStruct
{
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
}
