#pragma once

#include <vector>

namespace GamesImportWizard
{
    class SharedData
    {
        std::vector<long>* m_game_ids;
        std::vector<std::vector<long>>* m_scraper_game_ids;
        bool m_need_user_choice;

    protected:
        friend class DataProcessingPage;
        friend class GameSelectPage;

        SharedData();
        ~SharedData();

        std::vector<long>& gameIds();
        std::vector<std::vector<long>>& scraperGameIds();
        bool& needUserChoice();

        static SharedData& instance();
    };
}
