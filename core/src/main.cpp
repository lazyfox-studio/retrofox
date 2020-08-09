#include <iostream>

#include "window.h"

#include <database.h>

int main(int argc, char *argv[])
{
	try
	{
		Database::Connection db("sqlite.db");
		Database::Statement query(db,
			"CREATE TABLE IF NOT EXISTS `test` (" \
			"`ID` INT PRIMARY KEY NOT NULL," \
			"`NAME` TEXT NOT NULL," \
			"`AGE` INT NOT NULL" \
			");"
		);
		query.fetchStep();
		Database::Statement query2(db,
			"INSERT INTO `test` (`ID`, `NAME`, `AGE`) VALUES (1, \"Vasya1\", 123);"
		);
		query2.fetchStep();
		Database::Statement query3(db,
			"SELECT * FROM `test`;"
		);
		while (query3.fetchStep())
		{
			std::cout << query3.columnAs<int>(0) << query3.columnAs<std::string>(1) << query3.columnAs<int>(2);
		}
	}
	catch (std::exception & e)
	{
		std::cerr << e.what();
	}


	Window window;
	window.show();
	window.start();

	return 0;
}
