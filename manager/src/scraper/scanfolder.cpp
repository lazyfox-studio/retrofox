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

    std::vector<long> ScanFolder::result()
    {
        return m_result;
    }

    void ScanFolder::run()
    {
        PythonThreadController::instance().useInterpreter();
        m_result = PythonFunctions::findGamesInFolder(m_path, m_platform_id, m_db_path);
        PythonThreadController::instance().releaseInterpreter();
        emit finished();
    }
}
