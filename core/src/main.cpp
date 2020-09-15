#include <iostream>

#include <database.h>
#include <api-service.h>

#include "mainwindow.h"
#include "scraper.h"


int main(int argc, char *argv[])
{
	PythonMainThread py_main_thread;
	MainWindow window("RetroFox", 100, 100, 800, 600);
	//window.setFullscreen();
	window.show();
	window.start();

	return 0;
}
