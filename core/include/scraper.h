#pragma once

#include <string>

#include <database.h>
#include <pythonenv.h>
#include <pythonfunctions.h>

namespace Scraper
{
    void scanFloder(std::string path, long platform_id, const std::string& db_path);
    void findGamesInformation(const std::string& db_path);

    void cleanCache(const std::string& db_path);
};