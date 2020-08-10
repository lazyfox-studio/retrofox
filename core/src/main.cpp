#include <iostream>

#include "window.h"

#include <database.h>

int main(int argc, char *argv[])
{
	try
	{
		Database::Connection db("sqlite.db");
		Database::Statement query;
		query = db.query(
			"CREATE TABLE IF NOT EXISTS `test` (" \
			"`ID` INT PRIMARY KEY NOT NULL," \
			"`NAME` TEXT NOT NULL," \
			"`AGE` INT NOT NULL" \
			");"
		);
		query.execute();
		//query = db.query("INSERT INTO `test` (`ID`, `NAME`, `AGE`) VALUES (1, \"Vasya1\", 123);");
		query.execute();
		query = db.query("SELECT * FROM `test`;");
		Database::Row row;
		while (row = query.fetchRow())
		{
			std::cout << row.column<int>("ID") << row.column<std::string>("NAME") << row.column<int>(2);
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
