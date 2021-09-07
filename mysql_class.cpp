#include<cstdio>
#include"mysql_class.h"
using namespace mysql_class;

Table MySQL::get_result(){
	auto result=mysql_store_result(m_mysql);
	auto rows=mysql_num_rows(result);
	auto fields=mysql_num_fields(result);
	Table tab(rows,Row(fields));
	for(auto &i:tab){
		auto row=mysql_fetch_row(result);
		for(decltype(fields) j=0;j<fields;j++)
			i[j]=row[j];
	}
	mysql_free_result(result);
	return tab;
}
void mysql_class::default_print_tab(const Table &tab){
	for(const auto &i:tab){
		for(const auto &j:i)
			printf("%-7s ",j.c_str());
		putchar('\n');
	}
}