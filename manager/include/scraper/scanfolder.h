#pragma once

#include <QThread>

#undef slots
#include <pythonfunctions.h>
#define slots

namespace Scraper
{
    class ScanFolder : public QThread
    {
    protected:
        std::string m_path;
        long m_platform_id;
        std::string m_db_path;

    public:
        ScanFolder(std::string path, long platform_id, const std::string& db_path);
        ~ScanFolder();

    public slots:
        void run();
    };
}
