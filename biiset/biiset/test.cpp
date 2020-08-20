#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <list>
#include <vector>
#include <functional>
#include <algorithm>
#include <bitset>

using namespace std;

template<size_t _N>
class Bitset
{
public:
	Bitset() : m_bit((_N - 1) / 32 + 1), m_size(_N)
	{}
	void set(size_t pos)
	{
		if (pos >= m_size)
			return;
		size_t index = pos / 32;
		size_t offset = pos % 32;
		m_bit[index] |= (1 << offset);
	}
	bool test(size_t pos)
	{
		if (pos >= m_size)
			return false;
		size_t index = pos / 32;
		size_t offset = pos % 32;
		return (m_bit[index] & (1 << offset));
	}
public:
	size_t count()const
	{
		int bitCnttable[256] = {
			0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2,
			3, 3, 4, 3, 4, 4, 5, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3,
			3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3,
			4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4,
			3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5,
			6, 6, 7, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4,
			4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5,
			6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 2, 3, 3, 4, 3, 4, 4, 5,
			3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3,
			4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6,
			6, 7, 6, 7, 7, 8 };
		size_t size = m_bit.size();
		size_t count = 0;
		for (size_t i = 0; i < size; ++i)
		{
			int value = m_bit[i];
			int j = 0;
			while (j < sizeof(m_bit[0]))
			{
				unsigned char c = value;
				count += bitCnttable[c];
				++j;
				value >>= 8;
			}
		}
		return count;
	}
private:
	vector<int> m_bit;
	size_t      m_size;
};

int main()
{
	Bitset<10> bt;

	//0000 0001 00
	bt.set(2);
	bt.set(1);
	cout << bt.test(3) << endl;
	cout << bt.count() << endl;
	return 0;
}

//int main()
//{
//	bitset<10> bt(100);
//	cout << bt << endl;			//0001100100
//	bt.flip();
//	cout << bt << endl;			//1110011011
//	bt.set(2);
//	cout << bt << endl;			//1110011111
//	bt.set(3, 0);
//	cout << bt << endl;			//1110010111
//	cout << bt.count() << endl;	//	7
//	//是否设置任意比特位为1
//	cout << bt.any() << endl;	//1
//	//bt.reset();
//	//cout << bt.any() << endl;	//0
//	cout << bt.test(3) << endl;	//检测第三位是否为1
//	cout << bt.to_ulong() << endl;
//	cout << ~bt << endl;
//	cout << bt.flip() << endl;
//	return 0;
//}

//void main()
//{
//	bitset<10> bt;
//	cout << bt << endl;
//	bt.set(4);
//	cout << bt << endl;
//	bt.flip();
//	cout << bt << endl;		//对bt进行取反
//	cout << bt.count() << endl;		//统计位图bt中1的个数
//	cout << bt.size() << endl;
//
//	cout << bt.to_ulong() << endl;
//
//	bt.reset();
//	cout << bt << endl;
//
//}

//template<class T>
//size_t BKDRHash(const T *str)
//{
//	register size_t hash = 0;
//	while (size_t ch = (size_t)*str++)
//	{
//		hash = hash * 131 + ch;
//	}
//	return hash;
//}
//void main()
//{
//	const char *str = "hellobit";
//	size_t index = BKDRHash(str);
//	cout << index << endl;
//}

//int main()
//{
//	// 统计v2中有多少个偶数
//	vector<int> v2{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14 };
//	cout << count_if(v2.begin(), v2.end(), [](int a)->bool{return (a % 2 == 0); }) << endl;
//	return 0;
//}

////int _Count_if(int *_First, int *_Last, _Pr_Pred)
////{
////	int _Count = 0;
////	for (; _First != _Last; ++_First)
////	{
////		if (_Pred(*_First))		//if(IsOdd(*_First))
////			++_Count;
////	}
////	return (_Count);
////}
//
//bool IsOdd(int i)
//{
//	return ((i % 2) == 0);
//}
//
//int main()
//{
//	vector<int> v{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	//统计v中有多少偶数
//	cout << count_if(v.begin(), v.end(), IsOdd) << endl;
//	return 0;
//}

//struct gt
//{
//	bool operator()(int a, int b)
//	{
//		return a > b;
//	}
//};
//int main()
//{
//	list<int> mylist = { 0, 5, 6, 8, 7, 2, 9, 1, 3, 8 };
//	//mylist.sort(greater<int>());
//	mylist.sort(gt());
//	for (const auto &e : mylist)
//		cout << e << "-->";
//	cout << endl;
//	return 0;
//}

//int main()
//{
//	vector<int> v;
//	v.resize(10);
//	//v.reserve(10);
//	v.insert(v.end(), 2, 5);
//}