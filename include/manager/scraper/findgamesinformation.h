#pragma once

#include <QThread>

#include <vector>

#include <api-service/api-service.h>

namespace Scraper
{
    class FindGamesInformation : public QThread
    {
        Q_OBJECT

    protected:
        std::string m_api_key;
        std::vector<long> m_game_ids;
        std::string m_db_path;

        std::vector<std::vector<long>> m_result;

    public:
        FindGamesInformation(std::string api_key, std::vector<long> game_ids, const std::string& db_path);
        ~FindGamesInformation();

        std::vector<std::vector<long>> result();

    public slots:
        void run();

    signals:
        void finished();
        void gameFetched(int current, int total);
    };
}
