#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <forward_list> //C++11
#include <list>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <functional>
//#include <hash_set>
//#include <unordered_set>
//#include <hash_map>
//#include <unordered_map>

using namespace std;

void main()
{
	map<int, string> ismap = { { 1, "Student" }, { 2, "Teacher" }, { 3, "Friend" }, { 4, "Bit" } };
	ismap[1] = "ѧ��";
	ismap[2] = "��ʦ";
	ismap[3] = "����";
	ismap[-1] = "hehe";
	int key = 10;
	auto ret_it = ismap.find(key);
	if (ret_it != ismap.end())
	{
		//
	}
	else
		cout << "������." << endl;
	ismap[5] = "����"; //�൱�����ݲ���  <5-����>
	for (const auto &e : ismap)
		cout << e.first << " : " << e.second << endl;

	//map<int, string> ismap;
	//pair<int, string> v[] = { { 3, "Student" }, { 1, "Friend" }, { 2, "Bit" }, { 4, "Teacher" } };		//���ս��Ϊ����map
	//int n = sizeof(v) / sizeof(v[0]);
	//for (int i = 0; i < n; ++i)
	//	ismap.insert(v[i]);
	//auto it = ismap.begin();
	////it->first = 10;				//itΪ��������
	////it->second[0] = 's';
	//for (const auto &e : ismap)
	//	cout << e.first << " : " << e.second << endl;
}

//class Foo
//{
//public:
//	Foo(int n, double x) : m_n(n), m_x(x)
//	{}
//	int m_n;
//	double m_x;
//};
//void main()
//{
//	vector<Foo> v;
//	auto someIterator = v.begin();
//	//emplace�ǵ��ù��캯����ֱ���������й���һ��Ԫ�ء�û����ʱ��������
//	//��insert��push�ǿ�����������Ԫ�ؿ����������С��������ʱ����
//	someIterator = v.emplace(someIterator, 42, 3.28);	//û����ʱ��������
//	//v.insert(someIterator, 42, 3.28);			//error��insert��֧�ֶ��в���������в���
//	v.insert(someIterator, Foo(42, 3.28));
//}

//void main()
//{
//	vector<int> v = { 25, 46, 89, 74, 56, 31, 49, 5, 7, 847 };
//	set<int> s(v.begin(),v.end());
//	//s.emplace(100);
//	s.insert(100);
//	set<int>::iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}

//int main()
//{
//	vector<int> v = { 25, 46, 89, 74, 56, 31, 25, 25, 25, 25, 25, 49, 5, 7, 847 };
//	set<int> s(v.begin(), v.end());					//�������ظ�ֵ
//	cout << "size = " << s.size() << endl;
//	cout << "count = " << s.count(25) << endl;
//	set<int>::iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	multiset<int> multis(v.begin(), v.end());		//�����ظ�ֵ
//	cout << "multi size = " << multis.size() << endl;
//	cout << "multi count = " << multis.count(25) << endl;
//	for (const auto &e : multis)
//		cout << e << " ";
//	cout << endl;
//
//	//vector<int> v = { 25, 46, 89, 74, 56, 31, 49, 5, 7, 847 };
//	//set<int> s(v.begin(), v.end());
//	//set<int>::iterator  it = s.begin();
//	//while (it != s.end())
//	//{
//	//	cout << *it << " ";
//	//	++it;
//	//}
//	//cout << endl;
//	//set<int>::reverse_iterator rit = s.rbegin();
//	//while (rit != s.rend())
//	//{
//	//	cout << *rit << " ";
//	//	++rit;
//	//}
//	//cout << endl;
//
//	return 0;
//}

//int main()
//{
//	vector<int> iv = { 25, 46, 89, 74, 56, 31, 49, 5, 7, 847 };
//	set<int> s(iv.begin(), iv.end());
//	set<int>::iterator it = s.begin(); //const_it
//	*it = 20;  //const  ==>
//
//	//list<int> mylist = { 25, 46, 89, 74, 56, 31, 49, 5, 7, 847 };
//	//list<int>::iterator it = mylist.begin();
//	//cout << *it << endl;
//	//*it = 1000;
//	//cout << *it << endl;
//
//	//vector<int> v = { 25, 46, 89, 74, 56, 31, 49, 5, 7, 847 };
//	//const set<int> s(v.begin(), v.end());
//	////s.erase(5);				//const set��֧��erase��insert����
//	////s.insert(20);
//	//set<int>::const_iterator it = s.begin();
//	//*it = 20;			//������set����constset��it��s.begin()����s.cbegin()�������ܶ�*it���и�ֵ�����ϵ�ֵ�������޸�
//	//while (it != s.end())
//	//{
//	//	cout << *it << " ";
//	//	++it;
//	//}
//
//	return 0;
//}

//int main()
//{
//	vector<int> v = { 25, 46, 89, 74, 56, 31, 49, 5, 7, 847 };
//	set<int> s(v.begin(), v.end());
//	set<int> s1 = s;
//	for (const auto &e : s)
//		cout << e << " ";
//	cout << endl;
//
//	//set<int> s = { 25, 46, 89, 74, 56, 31, 49, 5, 7, 847 };		//���򼯺�
//	//for (const auto &e : s)
//	//	cout << e << " ";
//	//cout << endl;
//
//	return 0;
//}

//int main()
//{
//	pair<int, string> v1 = { 1, "qwer" };
//	pair<int, string> v2 = { 2, "asdf" };
//	cout << v1.first << " : " << v1.second << endl;
//	pair<string, string> v3 = make_pair("1-1", "Ԫ����");
//	cout << v3.first << " : " << v3.second << endl;
//	return 0;
//}

//int main()
//{
//	forward_list<int> mylist;		//ǰ������ֻ֧��push_front
//	for (int i = 1; i <= 10; ++i)
//		mylist.push_front(i);
//	//mylist.reverse();
//	for (const auto &e : mylist)
//		cout << e << "->";
//	cout << endl;
//	return 0;
//}