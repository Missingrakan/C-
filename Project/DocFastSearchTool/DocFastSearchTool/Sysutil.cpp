#define _CRT_SECURE_NO_WARNINGS 1

#include "Sysutil.h"

//void DirectionList(const string &path);
void DirectionList(const string &path, vector<string> &subfile, vector<string> &subdir)
{
	string _path = path;
	_path += "\\*.*";

	_finddata_t file;
	long handle = _findfirst(_path.c_str(), &file);		//搜索path路径下的第一个文件

	if (handle == -1)
	{
		perror("_findfirst");
		return;
	}

	do
	{
		if (strcmp(file.name, ".") == 0 ||
			strcmp(file.name, "..") == 0)		//skip . and ..
			continue;
		if (file.attrib & _A_SUBDIR)
		{
			////目录
			//cout << file.name << endl;
			//string tmp_path = path;
			//tmp_path += "\\";
			//tmp_path += file.name;
			//DirectionList(tmp_path);
			subdir.push_back(file.name);
		}
		else
			//cout << file.name << endl;
			subfile.push_back(file.name);
	} while (_findnext(handle,&file) == 0);

	_findclose(handle);
}