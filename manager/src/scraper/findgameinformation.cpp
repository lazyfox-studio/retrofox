#include "scraper/findgameinformation.h"

namespace Scraper
{

    FindGameInformation::FindGameInformation(std::string api_key, long game_id, const std::string &db_path) :
        m_api_key(api_key), m_game_id(game_id), m_db_path(db_path)
    {

    }

    FindGameInformation::~FindGameInformation()
    {

    }

    void FindGameInformation::run()
    {
        PythonFunctions::findGame(m_api_key, m_game_id, m_db_path);
    }

}
