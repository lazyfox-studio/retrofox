#pragma once

#include <QThread>
#include <QDebug>

#include <api-service/api-service.h>

namespace Scraper
{
    class ScanFolder : public QThread
    {
        Q_OBJECT

    protected:
        std::string m_path;
        long m_platform_id;
        std::string m_db_path;

        std::vector<long> m_result;

    public:
        ScanFolder(std::string path, long platform_id, const std::string& db_path);
        ~ScanFolder();

        std::vector<long> result();

    public slots:
        void run();

    signals:
        void finished();
    };
}
