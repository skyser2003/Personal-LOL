namespace ApiSrcGenerator
{
    public class RiotApiType
    {
        public enum ApiType
        {
            // Champion mastery
            CHAMPION_MASTERY_MASTERIES_BY_SUMMONER,
            CHAMPION_MASTERY_MASTERIES_BY_SUMMONER_AND_CHAMPION,
            CHAMPION_MASTERY_SCORES_BY_SUMMONER,

            // Champion
            CHAMPION_CHAMPIONS,
            CHAMPION_CHAMPIONS_BY_ID,

            // League
            LEAGUE_CHALLENGERLEAGUES_BY_QUEUE,
            LEAGUE_BY_SUMMONER,
            LEAGUE_BY_LEAGUE,
            LEAGUE_MASTERLEAGUES_BY_QUEUE,
            LEAGUE_POSITIONS_BY_SUMMONER,

            // Static data
            STATIC_CHAMPIONS,
            STATIC_CHAMPIONS_BY_ID,
            STATIC_ITEMS,
            STATIC_ITEMS_BY_ID,
            STATIC_LANGUAGE_STRINGS,
            STATIC_LANGUAGES,
            STATIC_MAPS,
            STATIC_MASTERIES,
            STATIC_MASTERIES_BY_ID,
            STATIC_PROFILE_ICONS,
            STATIC_REALMS,
            STATIC_RUNES,
            STATIC_RUNES_BY_ID,
            STATIC_SUMMONER_SPELLS,
            STATIC_SUMMONER_SPELLS_BY_ID,
            STATIC_VERSIONS,

            // Status
            STATUS_SHARD_DATA,

            // Match
            MATCH_MATCHES_BY_ID,
            MATCH_MATCHLISTS_BY_ACCOUNT,
            MATCH_MATCHLISTS_BY_ACCOUNT_RECENT,
            MATCH_TIMELINES_BY_MATCH,
            MATCH_BY_TOURNAMENT_CODE_IDS,
            MATCH_BY_TOURNAMENT_CODE,

            // Spectator
            SPECTATOR_ACTIVE_GAMES_BY_SUMMONER,
            SPECTATOR_FEATURED_GAMES,

            // Summoner
            SUMMONER_SUMMONERS_BY_ACCOUNT,
            SUMMONER_SUMMONERS_BY_NAME,
            SUMMONER_SUMMONERS_BY_SUMMONER_ID,

            // TODO - these three categories might have a chance to be used one day... or not
            // Third party code
            // Tournament stub
            // Tournament
        }
    }
}