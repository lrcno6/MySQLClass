#include"table.h"
using namespace mysql_class;
Table::Table(MYSQL_RES *result):m_row(mysql_num_rows(result)),m_column(mysql_num_fields(result)){
	m_table=new std::string*[m_row];
	for(int i=0;i<m_row;i++){
		m_table[i]=new std::string[m_column];
		MYSQL_ROW row=mysql_fetch_row(result);
		for(int j=0;j<m_column;j++)
			m_table[i][j]=row[j];
	}
}