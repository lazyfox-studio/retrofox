#pragma once

#include <string>
#include <filesystem>
#include <database.h>

class Scraper
{
    static std::string db_path;

public:
    static void setDatabasePath(const std::string& path);

    static void scanFloder(std::string path, int platform_id);
    static void findGameInformation(std::string path);
};