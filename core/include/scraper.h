#pragma once

#include <string>

#include <database.h>
#include <pythonenv.h>

namespace Scraper
{
    void scanFloder(std::string path, int platform_id, const std::string& db_path);
    void findGamesInformation(const std::string& db_path);
};