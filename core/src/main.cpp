#include <iostream>

#include <database.h>
#include <pythonenv.h>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
	try
	{
		PythonEnv::instance().loadModule("test.py");
		int result = PythonEnv::instance().callFunction("test.py", "someMagicFunctionWithoutArgs").cast<int>();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what();
	}

	MainWindow window("RetroFox", 100, 100, 800, 600);
	//window.setFullscreen();
	window.show();
	window.start();

	return 0;
}
