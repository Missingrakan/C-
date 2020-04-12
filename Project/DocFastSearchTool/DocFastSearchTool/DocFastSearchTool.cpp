#define _CRT_SECURE_NO_WARNINGS 1

#include "common.h"
#include "Susutil.h"
#include "./sqlite/sqlite3.h"

//静态库使用sqlite
#pragma comment(lib,"./sqlite/sqlite3.lib")

void Test_DirectionList()
{
	const string& path = "C:\\Users\\暮星之辰\\Desktop\\Day code";
	vector<string> subfile, subdir;
	DirectionList(path, subfile, subdir);
	//DirectionList(path);

	for (const auto &e : subfile)
		cout << e << endl;
	for (const auto &e : subdir)
		cout << e << endl;
}

void Test_Sqlite()
{
	//数据打开
	sqlite3 *db;
	int rc = sqlite3_open("test.db", &db);
	if (rc != SQLITE_OK)
		cout << "Open databases failed." << endl;
	else
		cout << "Open databases successed." << endl;

	//操作数据库
	string sql = "select * from my_tb";
	char **result;
	int row;
	int col;
	char *zErrMsg = 0;

	sqlite3_get_table(db, sql.c_str(), &result, &row, &col, &zErrMsg);

	for (int i = 1; i < row; ++i)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%-5s", *(result + (i*col) + j));
		}
		cout << endl;
	}

	sqlite3_free_table(result);
	//关闭数据库
	sqlite3_close(db);
}

int main()
{
	//Test_DirectionList();
	Test_Sqlite();
	return 0;
}

/*
static int callback(void *data, int argc, char **argv, char **azColName)
{
	int i = 0;
	fprintf(stderr, "%s:\n", (const char*)data);
	for (i = 0; i < argc; i++)
	{
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

void Test_Sqlite()
{
	//数据库打开
	sqlite3 *db;
	int rc = sqlite3_open("test.db", &db);
	if (rc != SQLITE_OK)
		cout << "Open database failed.\n" << endl;
	else
		cout << "Open database successed.\n" << endl;

	//操作数据库
	char *zErrMsg = nullptr;
	const char *data = "Callback function called.";
	//sqlite3_exec(sqlite3*, const char *sql, sqlite_callback, void *data, char **errmsg)；
	//string sql = "create table my_tb(id int,name varchar(20),path varchar(100))";
	//string sql = "insert into my_tb values(1,'abc','C:\\')";
	string sql = "select id,name,path from my_tb where id = 1";
	rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else
	{
		//fprintf(stdout, "Table create successfully\n");
		//fprintf(stdout, "Insert Data successfully\n");
		fprintf(stdout, "Select Data successfully\n");
	}
	sqlite3_close(db);
}

int main(int argc, char *argv[])
{
	//Test_DirectionList();
	Test_Sqlite();
	return 0;
}
*/