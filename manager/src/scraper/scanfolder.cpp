#include "scraper/scanfolder.h"

namespace Scraper
{
    ScanFolder::ScanFolder(std::string path, long platform_id, const std::string &db_path) : m_path(path),
        m_platform_id(platform_id), m_db_path(db_path)
    {

    }

    ScanFolder::~ScanFolder()
    {

    }

    void ScanFolder::run()
    {
        PythonFunctions::findGamesInFolder(m_path, m_platform_id, m_db_path);
    }
}
