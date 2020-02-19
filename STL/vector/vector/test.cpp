#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>

using namespace std;

namespace bit
{
	template<typename T>
	class vector
	{
	public:
		typedef T* iterator;
	public:
		vector() :start(nullptr), finish(nullptr), end_of_storage(nullptr)
		{}
		vector(size_t n, const T&value = T()) :start(nullptr), finish(nullptr), end_of_storage(nullptr) //const T&value = T()    ���ʼ��
		{
		}
	private:
		iterator start;
		iterator finish;
		iterator end_of_storage;
	};
};

int main()
{
	return 0;
}

//int main()
//{
//	vector<int> v{ 1, 2, 3, 4 };
//	auto it = v.begin();
//	while (it != v.end())
//	{
//		if (*it % 2 == 0)
//			it = v.erase(it);
//		else
//			++it;
//	}
//	for (auto &e : v)
//		cout << e << " ";
//	cout << endl;
//	return 0;
//}

//int main()
//{
//	vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
//	auto p = find(v.begin(), v.end(), 10);
//	auto it = find(v.begin(), v.end(), 3);
//
//	//1 it��ɾ�����ݵĺ��棬��ʱ���ݻ���ǰ�ƶ���������ʧЧ
//	//2 it��ɾ�����ݵ�ǰ�棬��ʱ��������ֱ���ݲ��ᷢ���仯����������Ȼ��Ч
//	v.erase(v.begin());//�������
//	//v.erase(p);	   //��������
//	cout << "*it = " << *it << endl;
//
//	return 0;
//}

//int main()
//{
//	vector<int> v = { 1, 2, 3, 4, 5 };
//	auto it = v.begin();
//	cout << "it = " << *it << endl;
//	//v.push_back();
//	v.resize(10);
//	//v.reserve(10);
//	it = v.begin();
//	cout << "it = " << *it << endl;//����Ԥ���ռ俪�����¿ռ䵼�µĵ�����ʧЧ
//	return 0;
//}

//int main()
//{
//	vector<int> v = { 1, 2, 3, 4, 5, 6 };
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//
//	auto it = find(v.begin(), v.end(), 3);
//	cout << "it = " << *it << endl;
//	v.push_back(10);
//	it = find(v.begin(), v.end(), 3);
//	cout << "it = " << *it << endl;//��ʱ������δʧЧ
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//
//	return 0;
//}

//int main()
//{
//	vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	vector<int> v2 = { 20, 21, 22, 23, 34, 35 };
//	for (auto &e : v1)
//		cout << e << " ";
//	cout << endl;
//	for (auto &e : v2)
//		cout << e << " ";
//	cout << endl;
//	v1.swap(v2);
//	for (auto &e : v1)
//		cout << e << " ";
//	cout << endl;
//	for (auto &e : v2)
//		cout << e << " ";
//	cout << endl;
//	return 0;
//}

//int main()
//{
//	vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	auto p = find(v1.begin(), v1.end(), 5);
//	auto p1 = find(v1.begin(), v1.end(), 10);
//	//auto it = v1.erase(p, p1);		//[5 6 7 8 9)
//	auto it = v1.erase(p);
//	for (auto &ele : v1)
//		cout << ele << " ";
//	cout << endl;
//
//	return 0;
//}

//int main()
//{
//	int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int n = sizeof(ar) / sizeof(int);
//	vector<int> v(ar, ar + n);
//
//	//C++11
//	vector<int> v1 = { 1, 2, 3, 4, 5, 67, 8, 9, 10 };
//	auto p = find(v1.begin(), v1.end(), 5);
//	v1.insert(v1.begin(), 100);
//	v1.insert(v1.end(), 200);
//	for (auto &ele : v1)
//		cout << ele << " ";
//	cout << endl;
//
//	return 0;
//}

//int main()
//{
//	vector<int> v;
//	for (int i = 1; i <= 10; ++i)
//	{
//		v.push_back(i);
//	}
//	auto it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	v.pop_back();
//
//	for (auto &ele : v)
//		cout << ele << " ";
//	cout << endl;
//
//	return 0;
//}

//int main()
//{
//	vector<int> v; //��̬����
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	v.push_back(1);  //����
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//}

//int main()
//{
//	vector<int> v;
//	for (int i = 1; i <= 10; ++i)
//	{
//		v.push_back(i);
//		//v.push_front(i);//error,������֧��ͷ�嵫��insert()����
//	}
//	for (auto &e : v)
//		cout << e << " ";
//	cout << endl;
//	return 0;
//}

//int main()
//{
//	vector<int> v;
//	//v.reserve(100);		//�������֪����Ҫ���ٿռ䣬����ΪԤ���ռ䣬����ϵͳ����
//	for (int i = 0; i<100; ++i)
//	{
//		cout << "capacity = " << v.capacity() << endl;
//		v.push_back(i);
//	}
//}


//void Print(vector<int> &v)
//{
//	for (int i = 0; i<v.size(); ++i)
//		cout << v[i] << " ";
//	cout << endl;
//}
//int main()
//{
//	int ar[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	vector<int> v(ar, ar + 10);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	Print(v);
//
//	v.resize(15);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	Print(v);
//
//	return 0;
//}

//int main()
//{
//	int ar[3] = { 1, 2, 3 };
//	vector<int> v(ar, ar + 3);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	Print(v);
//	v.reserve(10);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	v.reserve(100);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	v.reserve(50);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	Print(v);
//
//	return 0;
//}

//int main()
//{
//	vector<int> v;
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	v.push_back(1);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	v.push_back(2);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	v.push_back(3);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	v.push_back(4);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	v.push_back(5);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	v.push_back(6);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	v.push_back(7);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//
//	return 0;
//}

//int main()
//{
//	int ar[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	vector<int> v4(ar, ar + 10);
//
//	//�����±�[]  operator[]
//	for (int i = 0; i < v4.size(); ++i)
//		cout << v4[i] << " ";
//	cout << endl;
//
//	//����at() ����С���Ƿ�Խ��
//	for (int i = 0; i < v4.size(); ++i)
//		cout << v4.at(i) << " ";
//	cout << endl;
//
//	//���õ�����
//	vector<int>::iterator it = v4.begin();
//	while (it != v4.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	//���÷��������
//	vector<int>::reverse_iterator rit = v4.rbegin();
//	while (rit != v4.rend())
//	{
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//
//	return 0;
//}

//int main()
//{
//	//Ĭ�Ϲ���  veator()
//	vector<int> v1;
//
//	//vector��size_type n, const value_type& val = value_type()�� ���첢��ʼ��n��val
//	vector<int> v2(10, 5);
//	for (int i = 0; i < v2.size(); i++)
//		cout << v2[i] << " ";
//	cout << endl;
//	//vector(const vector& x); ���ص㣩 ��������
//	vector<int> v3(v2);
//	for (int i = 0; i < v3.size(); i++)
//		cout << v3[i] << " ";
//	cout << endl;
//
//	//vector( value_type *first, value_type *last);
//	int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	vector<int> v4(ar, ar + 10);
//	for (int i = 0; i<v4.size(); ++i)
//		cout << v4[i] << " ";
//	cout << endl;
//
//	//vector (InputIterator first, InputIterator last);
//	vector<int> v5(v4.begin(), v4.end());
//	for (int i = 0; i<v5.size(); ++i)
//		cout << v5[i] << " ";
//	cout << endl;
//
//	return 0;
//}