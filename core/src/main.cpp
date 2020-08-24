#include <iostream>

#include <database.h>
#include <pythonfunctions.h>

#include "mainwindow.h"

#include "scraper.h"

int main(int argc, char *argv[])
{
	//Scraper::scanFloder("Z:/PlayStation", 10, "testbase.db");
	Scraper::findGamesInformation("testbase.db");
	//MainWindow window("RetroFox", 100, 100, 800, 600);
	//window.setFullscreen();
	//window.show();
	//window.start();

	return 0;
}
