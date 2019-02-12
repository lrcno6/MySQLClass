#ifndef _TABLE_H_
#define _TABLE_H_
#include<string>
#include<mysql/mysql.h>
namespace mysql_class{
	class Table{
		public:
			explicit Table(MYSQL_RES*);
			Table(const Table&)=delete;
			Table(Table &&other):m_row(other.m_row),m_column(other.m_column),m_table(other.m_table){
				other.m_table=nullptr;
			}
			~Table(){
				for(int i=0;i<m_row;i++)
					delete[] m_table[i];
				delete[] m_table;
			}
			Table& operator=(const Table&)=delete;
			Table& operator=(Table&&)=delete;
			const std::string* operator[](size_t x)const{
				return m_table[x];
			}
		private:
			int m_row,m_column;
			std::string **m_table;
	};
}
#endif