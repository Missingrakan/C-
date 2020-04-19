#pragma once

#include "common.h"

class SqliteManager
{
public:
	SqliteManager();
	~SqliteManager();
public:
	void Open(const string &path);
	void Close();
	void ExecuteSql(const string &sql);
	void GetResultTable(const string &sql, int &row, int &col, char **&ppRet);
private:
	sqlite3 *m_db;
};

/////////////////////////////////////////////////////////////////////////////

class AutoGetResultTable
{
public:
	AutoGetResultTable(SqliteManager *db,const string &sql,int &row,int &col,char **&ppRet);
	~AutoGetResultTable();
public:
	////c++11		不允许拷贝构造和赋值
	//AutoGetResultTable(const AutoGetResultTable &) = delete;
	//AutoGetResultTable& operator=(const AutoGetResultTable &) = delete;
protected:
	AutoGetResultTable(const AutoGetResultTable &);
	AutoGetResultTable& operator=(const AutoGetResultTable &);
private:
	SqliteManager *m_db;
	char		  **m_ppRet;
};

/////////////////////////////////////////////////////////////////////////////
#define DOC_DB		"doc.db"
#define DOC_TABLE	"doc_tb"

/////////////////////////////////////////////////////////////////////////////

class DataManager
{
public:
	DataManager();
	~DataManager();
public:
	void InitSqlite();
public:
	void InsertDoc(const string &path, const string &doc);
	void GetDocs(const string &path, multiset<string> &docs);
	void DeleteDoc(const string &path, const string &doc);
public:
	void Search(const string &key, vector<pair<string, string>> &doc_path);
private:
	SqliteManager m_dbmgr;
};