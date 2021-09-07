#ifndef _MYSQL_CLASS_H_
#define _MYSQL_CLASS_H_
	#include<string>
	#include<vector>
	#include<stdexcept>
	#include<mysql/mysql.h>

	namespace mysql_class{
		typedef std::vector<std::string> Row;
		typedef std::vector<Row> Table;
		
		class MySQL{
			public:
				MySQL():m_mysql(mysql_init(nullptr)){
					if(m_mysql==nullptr)
						throw std::runtime_error("MySQL::MySQL(): MySQL Init Failed!");
				}
				MySQL(const MySQL&)=delete;
				MySQL(MySQL &&other)noexcept:m_mysql(other.m_mysql){
					other.m_mysql=nullptr;
				}
				virtual ~MySQL()noexcept{
					mysql_close(m_mysql);
				}

				MySQL& operator=(const MySQL&)=delete;
				MySQL& operator=(MySQL&&)=delete;

				void connect(const char *host,const char *user,const char *passwd,const char *db){
					if(mysql_real_connect(m_mysql,host,user,passwd,db,0,nullptr,CLIENT_FOUND_ROWS)==nullptr)
						throw std::invalid_argument(mysql_error(m_mysql));
				}
				void connect(const std::string &host,const std::string &user,const std::string &passwd,const std::string &db){
					connect(host.c_str(),user.c_str(),passwd.c_str(),db.c_str());
				}
				void query(const char *cmd){
					if(mysql_query(m_mysql,cmd))
						throw std::runtime_error(mysql_error(m_mysql));
				}
				void query(const std::string &cmd){
					query(cmd.c_str());
				}
				Table get_result();
			protected:
				MYSQL *m_mysql;
		};

		void default_print_tab(const Table&);
	}
#endif