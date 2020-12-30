#pragma once

#include <vector>

namespace GamesImportWizard
{
    class SharedData
    {
        long m_platform_id;
        std::vector<long>* m_game_ids;
        std::vector<std::vector<long>>* m_scraper_game_ids;
        bool m_need_user_choice;

    protected:
        friend class PathSelectPage;
        friend class DataProcessingPage;
        friend class GameSelectPage;

        SharedData();
        ~SharedData();

        long platformId();
        std::vector<long>& gameIds();
        std::vector<std::vector<long>>& scraperGameIds();
        bool& needUserChoice();

        static SharedData& instance();
    };
}
