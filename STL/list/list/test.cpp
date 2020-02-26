#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <list>

using namespace std;


int main()
{
	list<int> mylist = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	auto it = mylist.begin();
	while (it != mylist.end())
	{
		if (*it == 5)
			it = mylist.erase(it);			//不影响后面迭代器的使用
		else
			it++;
	}
	for (const auto &e : mylist)
		cout << e << "-->";
	cout << "Over." << endl;

	return 0;
}

//int main()
//{
//	list<int> mylist = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	for (const auto &e : mylist)
//		cout << e << "-->";
//	cout << "Over." << endl;
//	auto first = find(mylist.begin(), mylist.end(), 3);
//	auto last = find(mylist.begin(), mylist.end(), 8); 
//	auto it = mylist.erase(first, last);				//删除一个区间
//	cout << "it = " << *it << endl;
//	for (const auto &e : mylist)
//		cout << e << "-->";
//	cout << "Obver." << endl;
//
//	return 0;
//}

//int main()
//{
//	list<int> mylist = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	auto pos = find(mylist.begin(), mylist.end(), 4);
//	auto pos1 = find(mylist.begin(), mylist.end(), 1); 
//	auto pos2 = find(mylist.begin(), mylist.end(), 8); 
//	cout << "pos = " << *pos << endl;
//	cout << "pos1 = " << *pos1 << endl;
//	cout << "pos2 = " << *pos2 << endl;
//	//mylist.push_front(100);		//此时迭代器不会失效
//	pos = mylist.erase(pos);
//	cout << "pos = " << *pos << endl;
//	cout << "pos1 = " << *pos1 << endl;
//	cout << "pos2 = " << *pos2 << endl;
//
//	return 0;
//}

//int main()
//{
//	list<int> mylist = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	cout << "size = " << mylist.size() << endl;
//	//cout << "capacity = " >> mylist.capacity << endl;		//error
//	cout << "front = " << mylist.front() << endl;
//	cout << "back = " << mylist.back() << endl;
//	for (const auto &e : mylist)
//		cout << e << "-->";
//	cout << "Over." << endl;
//
//	mylist.push_front(100);
//	mylist.push_back(100);
//	mylist.pop_front();
//	mylist.pop_back();
//
//	auto pos = find(mylist.begin(), mylist.end(), 4);
//	mylist.insert(pos, 100);
//	//mylist.clear();
//	cout << "pos = " << *pos << endl;
//	pos = mylist.erase(pos);			//迭代器未更新可能导致迭代器失效
//	cout << "pos = " << *pos << endl;
//
//
//	for (const auto &e : mylist)
//		cout << e << "-->";
//	cout << "Over." << endl;
//
//	return 0;
//}

//int main()
//{
//	list<int> mylist = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	auto it1 = mylist.begin();
//	cout << typeid(it1).name() << endl;			//List_iterator
//	*it1 = 100;
//	const list<int> mylist1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	auto it2 = mylist1.begin();
//	cout << typeid(it2).name() << endl;			//List_const_iterator
//	//*it2 = 100;			//error
//
//	return 0;
//}

//int main()
//{
//	list<int> mylist = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	for (const auto &e : mylist)
//		cout << e << "-->";
//	cout << "Over." << endl;
//
//	list<int>::iterator it = mylist.begin();
//	while (it != mylist.end())
//	{
//		cout << *it << "-->";
//		++it;
//	}
//	cout << "Over." << endl;
//
//	auto it1 = mylist.begin();
//	while (it1 != mylist.end())
//	{
//		cout << *it1 << "-->";
//		++it1;
//	}
//	cout << "Over." <<endl;
//
//	auto rit = mylist.rbegin();
//	while (rit != mylist.rend())
//	{
//		cout << *rit << "-->";
//		++rit;
//	}
//	cout << "Over." << endl;
//
//	list<int>::reverse_iterator rit1 = mylist.rbegin();
//	while (rit1 != mylist.rend())
//	{
//		cout << *rit1 << "-->";
//		++rit1;
//	}
//	cout << "Over." << endl;
//
//	return 0;
//}

//int main()
//{
//	int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	list<int> mylist;
//	list<int> mylist1(10, 2);
//	list<int> mylist2(mylist1);
//	list<int> mylist3(ar, ar + 10);
//	list<int> mylist4(mylist3.begin(), mylist3.end());
//	list<int> mylist5 = { 1, 2, 3, 4, 5 };
//
//	for (const auto &e : mylist5)
//		cout << e << "-->";
//	cout << "Over." << endl;
//
//	return 0;
//}