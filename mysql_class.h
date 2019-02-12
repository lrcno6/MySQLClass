#ifndef _MYSQL_CLASS_H_
#define _MYSQL_CLASS_H_
#include<string>
#include<mysql/mysql.h>
#include"table.h"
namespace mysql_class{
	class MySQL{
		public:
			MySQL():m_connected(false){
				mysql_init(&m_sql);
			}
			~MySQL(){
				close();
			}
			bool connect(const char *host,const char *user,const char *password,const char *database){
				return m_connected?false:m_connected=mysql_real_connect(&m_sql,host,user,password,database,0,nullptr,CLIENT_FOUND_ROWS);
			}
			bool connect(const std::string &host,const std::string &user,const std::string &password,const std::string &database){
				return connect(host.c_str(),user.c_str(),password.c_str(),database.c_str());
			}
			void close(){
				if(m_connected){
					mysql_close(&m_sql);
					m_connected=false;
				}
			}
			bool command(const char *cmd){
				return !mysql_query(&m_sql,cmd);
			}
			bool command(const std::string &cmd){
				return command(cmd.c_str());
			}
			Table result(){
				auto res=mysql_store_result(&m_sql);
				Table table(res);
				mysql_free_result(res);
				return table;
			}
		private:
			bool m_connected;
			MYSQL m_sql;
	};
}
#endif