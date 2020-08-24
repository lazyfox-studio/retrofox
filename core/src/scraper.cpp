#include "scraper.h"

namespace Scraper
{
    void scanFloder(std::string path, long platform_id, const std::string& db_path)
    {
        PythonFunctions::findGamesInFolder(path, platform_id, db_path);
    }

    void findGamesInformation(const std::string& db_path)
    {
        Database::Connection base(db_path);
        auto games = base.getColumn<std::string>("SELECT `id` FROM `games`;");

        //TODO: ADD KEY GET FROM SERVER
        std::string stolen_api_key = "445fcbc3f32bb2474bc27016b99eb963d318ee3a608212c543b9a79de1041600";

        for (const auto& id : games)
        {
            PythonFunctions::findGame(stolen_api_key, std::stol(id), db_path);
        }
    }
}

