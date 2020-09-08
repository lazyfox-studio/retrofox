#pragma once

#include <QThread>

#undef slots
#include <pythonfunctions.h>
#define slots

namespace Scraper
{
    class FindGameInformation : public QThread
    {
        Q_OBJECT

    protected:
        std::string m_api_key;
        long m_game_id;
        std::string m_db_path;

    public:
        FindGameInformation(std::string api_key, long game_id, const std::string& db_path);
        ~FindGameInformation();

    public slots:
        void run();
    };
}
