#define _CRT_SECURE_NO_WARNINGS 1

#include "common.h"
#include "Sysutil.h"
#include "sqlite\sqlite3.h"
#include "DataManager.h"
#include "ScanManager.h"
#include "Sysframe.h"

char *title = "文档快速搜索工具";

int main(int argc, char *argv[])
{
	const string &path = "E:\\test";

	//创建扫描实例
	ScanManager::CreateInstance(path).ScanDirectory(path);

	//创建搜索实例
	DataManager &dm = DataManager::GetInstance();

	vector<pair<string, string>> doc_path;
	string key;
	while (1)
	{
		DrawFrame(title);
		DrawMenu();
		cin >> key;
		if (key == "exit")
			break;
		dm.Search(key, doc_path);
		int init_row = 5;
		int count = 0;
		string prefix, highlight, suffix;
		for (const auto &e : doc_path)
		{
			string doc_name = e.first;
			string doc_path = e.second;

			DataManager::SplitHighlight(doc_name, key, prefix, highlight, suffix);

			SetCurPos(2, init_row + count++);
			cout << prefix;
			ColourPrintf(highlight.c_str());
			cout << suffix;

			SetCurPos(33, init_row + count - 1);
			printf("%-50s", doc_path.c_str());

		}
		SystemEnd();
		system("pause");
	}
	SystemEnd();
	return 0;
}

/*
void Test_DirectionList()
{
	const string& path = "E:\\test";
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

void Test_SqliteManager()
{
	SqliteManager sm;
	sm.Open("doc.db");

	//string sql = "create table if not exists doc_tb(id integer primary key autoincrement,doc_name test,doc_path test)";
	//sm.ExecuteSql(sql);

	//string sql1 = "insert into doc_tb values(null,'stl.pdf','c:\\')";
	//sm.ExecuteSql(sql1);

	string sql = "select * from doc_tb";
	int row = 0;
	int col = 0;
	char **ppRet = 0;
	sm.GetResultTable(sql, row, col, ppRet);
	for (int i = 0; i <= row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			printf("%-10s", *(ppRet + (i*col) + j));
		}
		printf("\n");
	}
	sqlite3_free_table(ppRet);
}

void Test_Log()
{
	FILE *fp = fopen("Test.txt", "r");
	if (fp == NULL)
	{
		TRACE_LOG("Open File Error.");
		return;
	}
	else
		TRACE_LOG("Open File Success.");

	fclose(fp);
}

void Test_Set()
{
	vector<int> v = { 8, 0, 9, 9, 9, 9, 9, 3, 4, 7, 1, 5, 2, 6, 7 };

	multiset<int> s;	//保存重复数据
	//set<int> s;		//不保存重复数据
	for (const auto &e : v)
		s.insert(e);

	auto it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void Test_Map()
{
	//映射
	pair<int, string> p1 = { 1, "abc" };
	pair<int, string> p2 = { 5, "xyz" };
	pair<int, string> p3 = { 3, "lmn" };
	pair<int, string> p4 = { 2, "opq" };
	pair<int, string> p5 = { 9, "hjk" };
	pair<int, string> p6 = { 7, "rty" };

	//cout<<p1.first<<" : "<<p1.second<<endl;
	map<int, string> mp;
	mp.insert(p1);
	mp.insert(p2);
	mp.insert(p3);
	mp.insert(p4);
	mp.insert(p5);
	mp.insert(p6);

	for (const auto &e : mp)
		cout << e.first << " : " << e.second << endl;
}
void Test_Scan()
{
	const string& path = "E:\\test";
	ScanManager &sm = ScanManager::CreateInstance(path);
	sm.ScanDirectory(path);
}
void Test_Search()
{
	const string &path = "E:\\test";

	//创建扫描实例
	ScanManager::CreateInstance(path).ScanDirectory(path);
	//ScanManager sm;
	//sm.ScanDirectory(path);

	//创建搜索实例
	DataManager &dm = DataManager::GetInstance();
	//DataManager dm;

	string key;
	vector<pair<string, string>> doc_path;
	while (1)
	{
		cout << "请输入要搜索的关键字:>";
		cin >> key;
		dm.Search(key, doc_path);

		//显示结果
		printf("%-15s%-50s\n", "名称", "路径");
		for (const auto &e : doc_path)
			printf("%-15s%-50s\n", e.first.c_str(), e.second.c_str());
	}
}
void Test_ChineseConvert()
{
	string str = "毛国强";
	string pinyin = ChineseConvertPinYinAllSpell(str);
	cout << "pinyin = " << pinyin << endl;

	string initials = ChineseConvertPinYinInitials(str);
	cout << "initials = " << initials << endl;
}
void Test_Frame()
{
	DrawFrame(title);
	DrawMenu();
	SystemEnd();
}
int main()
{
	//Test_DirectionList();
	//Test_Sqlite();
	//Test_SqliteManager();
	//Test_Log();
	//Test_Set();
	//Test_Map();
	//Test_Scan();
	//Test_Search();
	//Test_ChineseConvert();
	Test_Frame();
	return 0;
}
*/
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