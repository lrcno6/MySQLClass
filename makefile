linux:table.cpp mysql_class.h table.h
	g++ -c table.cpp
	ar cr libmysql_class.a table.o
clean:
	rm table.o libmysql_class.a