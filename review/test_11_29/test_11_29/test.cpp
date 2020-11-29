#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <map>
#include <string>
#include<hash_set>
#include<unordered_set>
#include<hash_map>
#include<unordered_map>

using namespace std;

void main()
{
	hash_map<int, string> hmap = { { 1, "Student" }, { 3, "Friend" }, { 1, "Student1" }, { 4, "Bit" }, { 1, "Student2" }, { 2, "Teacher" } };
	hmap[1] = "学生";
	for (auto &e : hmap)
		cout << e.first << " : " << e.second << endl;
	cout << endl;

	unordered_map<int, string> unmap = { { 1, "Student" }, { 3, "Friend" }, { 1, "Student1" }, { 4, "Bit" }, { 1, "Student2" }, { 2, "Teacher" } };
	for (auto &e : unmap)
		cout << e.first << " : " << e.second << endl;
	cout << endl;

	cout << "================================================" << endl;

	hash_multimap<int, string> hmultimap = { { 1, "Student" }, { 3, "Friend" }, { 1, "Student1" }, { 4, "Bit" }, { 1, "Student2" }, { 2, "Teacher" } };
	for (auto &e : hmultimap)
		cout << e.first << " : " << e.second << endl;
	cout << endl;

	unordered_multimap<int, string> unmultimap = { { 1, "Student" }, { 3, "Friend" }, { 1, "Student1" }, { 4, "Bit" }, { 1, "Student2" }, { 2, "Teacher" } };
	for (auto &e : unmultimap)
		cout << e.first << " : " << e.second << endl;
	cout << endl;
}
/*
int main()
{
	hash_set<int> hset = { 43, 31, 435, 5, 43, 43, 43, 43, 44, 34, 4, 43, 6563, 2, 13, 14, 4545 };
	for (auto &e : hset)
		cout << e << " ";
	cout << endl;
	unordered_set<int> unset = { 43, 31, 435, 5, 43, 43, 43, 43, 44, 34, 4, 43, 6563, 2, 13, 14, 4545 };
	for (auto &e : unset)
		cout << e << " ";
	cout << endl;
	cout << "=======================================================" << endl;
	hash_multiset<int> hmultiset = { 43, 31, 435, 5, 43, 43, 43, 43, 44, 34, 4, 43, 6563, 2, 13, 14, 4545 };
	for (auto &e : hmultiset)
		cout << e << " ";
	cout << endl;
	unordered_multiset<int> unmultiset = { 43, 31, 435, 5, 43, 43, 43, 43, 44, 34, 4, 43, 6563, 2, 13, 14, 4545 };
	for (auto &e : unmultiset)
		cout << e << " ";
	cout << endl;
	return 0;
}
*/
/*
//at() 会检查边界
//[]   不会检查  ->键值不存在时，把数据插入
int main()
{
	//预判起始位置
	multimap<int, string> ismap1 = { { 1, "Student" }, { 1, "Student1" }, { 1, "Student2" }, { 2, "Teacher" }, { 3, "Friend" }, { 4, "Bit" } };
	for (const auto &e : ismap1)
		cout << e.first << " : " << e.second << endl;

	map<int, string> ismap = { { 1, "Student" }, { 1, "Student1" }, { 1, "Student2" }, { 2, "Teacher" }, { 3, "Friend" }, { 4, "Bit" } };
	ismap.insert(ismap.begin(), make_pair(8, "服务"));
	ismap.insert(ismap.end(), make_pair(0, "666"));
	auto pos = ismap.find(4);
	if (pos != ismap.end())
	{
		ismap.insert(pos, make_pair(7, "学习"));
	}
	for (const auto &e : ismap)
		cout << e.first << " : " << e.second << endl;

	return 0;
}
*/
/*
int main()
{
	map<int, string> ismap = { { 1, "Student" }, { 2, "Teacher" }, { 3, "Friend" }, { 4, "Bit" } };
	ismap[1] = "学生";
	ismap[2] = "老师";
	ismap[3] = "朋友";

	int key = 10;
	auto ret_it = ismap.find(key);
	if (ret_it != ismap.end())
	{
		//
	}
	else
		cout << "不存在" << endl;

	ismap[5] = "服务";
	for (const auto& e : ismap)
		cout << e.first << " : " << e.second << endl;
 	return 0;
}


int main()
{
	map<int, string> ismap;
	pair<int, string> v[] = { { 3, "Friend" }, { 1, "Student" }, { 2, "Teacher" }, { 4, "Bit" } };
	int n = sizeof(v) / sizeof(v[0]);
	for (int i = 0; i < n; ++i)
		ismap.insert(v[i]);

	auto it = ismap.begin();
	//it->first = 10;	//err
	//it->second = 's';	//err
	for (const auto& e : ismap)
		cout << e.first << " : " << e.second << endl;
	return 0;
}
*/