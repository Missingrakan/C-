#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <forward_list>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>
#include <functional>

using namespace std;

class Foo
{
public:
	Foo(int n, double x) : m_n(n), m_x(x)
	{}
	int m_n;
	double m_x;
};

int main()
{
	vector<Foo> v;
	auto someiterator = v.begin();
	someiterator = v.emplace(someiterator, 4, 12.34);		//没有临时变量产生
	//v.insert(someiterator, 4, 12.34);						//insert不支持如此传参
	v.insert(someiterator, Foo(4, 12.34));

	return 0;
}

#if 0
int main()
{
	vector<int> iv = { 43, 31, 435, 5, 6563, 2, 13, 14, 4545 };
	set<int> s(iv.begin(), iv.end());
	s.emplace(100);
	//s.insert(100);
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
	return 0;
}


int main()
{
	vector<int> iv = { 43, 31, 435, 5, 6563, 2, 43, 13, 43, 43, 43, 43, 43, 43, 43, 14, 4545 };
	set<int> s(iv.begin(), iv.end());
	cout << "size = " << s.size() << endl;
	cout << "count = " << s.count(43) << endl;
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout<<endl;

	//multiset：保留集合重复元素
	multiset<int> multis(iv.begin(), iv.end());
	cout<<"multi size = "<<multis.size()<<endl;
	cout<<"multi count = "<<multis.count(43)<<endl;  //0  1
	for(auto &e : multis)
		cout<<e<<" ";
	cout<<endl;
	return 0;
}

int main()
{
	vector<int> iv = { 43, 31, 435, 5, 6563, 2, 43, 13, 14, 4545 };
	set<int> s(iv.begin(), iv.end());
	set<int>::iterator it = s.begin();
	while(it != s.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
	set<int>::reverse_iterator rit = s.rbegin();
	while(rit != s.rend())
	{
		cout<<*rit<<" ";
		++rit;
	}
	cout<<endl;
	return 0;
}
#endif

#if 0
int main()
{
	list<int> mylist;
	vector<int> iv = { 43, 31, 435, 5, 6563, 2, 43, 13, 14, 4545 };
	set<int> s(iv.begin(), iv.end());
	set<int>::iterator it = s.begin(); //说明set中的普通迭代器也具有const属性 const_it
	*it = 20;  //const  ==>
	/*
	list<int> mylist = {43 ,31,435,5,6563,2,43,13,14,4545};
	list<int>::iterator it = mylist.begin();
	cout<<*it<<endl;
	*it = 1000;
	cout<<*it<<endl;
	*/
	return 0;
}
#endif

#if 0
int main()
{
	vector<int> v = { 43, 31, 435, 5, 6563, 2, 43, 13, 14, 4545 };
	const set<int> s(v.begin(), v.end());
	//const 修饰无法进行插入删除
	//s.erase(2);
	//s.insert(56);

	set<int>::const_iterator it = s.cbegin();
	while (it != s.cend())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	return 0;
}


int main()
{
	vector<int> v = { 43, 31, 435, 5, 6563, 2, 43, 13, 14, 4545 };
	set<int> s;
	//set 去重 && 有序集合
	set<int> s1(v.begin(), v.end());
	for (const auto &e : s1)
		cout << e << " ";
	cout << endl;
	set<int, greater<int>> s2 = { 43, 31, 435, 5, 6563, 2, 43, 13, 14, 4545 };
	for (const auto &e : s2)
		cout << e << " ";
	cout << endl;
	return 0;
}
#endif

#if 0
int main()
{
	pair<int, string> v1 = { 1, "abc" };
	pair<int, string> v2 = { 2, "xyz" };
	cout << v1.first << " : " << v1.second << endl;
	pair<string, string> v3 = make_pair("1-1", "元旦节");
	cout << v3.first << " : " << v3.second << endl;
	return 0;
}


int main()
{
	forward_list<int> mylist;
	for (int i = 1; i <= 10; ++i)
		mylist.push_front(i);
	mylist.reverse();
	for (const auto &e : mylist)
		cout << e << "->";
	cout << endl;
	return 0;
}
#endif