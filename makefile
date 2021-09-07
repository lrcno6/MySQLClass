libmysql_class.a:mysql_class.cpp mysql_class.h
	g++ -c mysql_class.cpp -Ofast
	ar cr libmysql_class.a mysql_class.o
clear:
	rm *.o *.a