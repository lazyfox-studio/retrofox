#include "manager/gamesimportwizard/shareddata.h"

namespace GamesImportWizard
{
    SharedData::SharedData()
    {
        m_game_ids = new std::vector<long>;
        m_scraper_game_ids = new std::vector<std::vector<long>>;
        m_need_user_choice = false;
    }

    SharedData::~SharedData()
    {
        delete m_game_ids;
        delete m_scraper_game_ids;
    }

    long SharedData::platformId()
    {
        return m_platform_id;
    }

    std::vector<long> &SharedData::gameIds()
    {
        return *m_game_ids;
    }

    std::vector<std::vector<long> > &SharedData::scraperGameIds()
    {
        return *m_scraper_game_ids;
    }

    bool &SharedData::needUserChoice()
    {
        return m_need_user_choice;
    }

    SharedData &SharedData::instance()
    {
        static SharedData inst;
        return inst;
    }
}
