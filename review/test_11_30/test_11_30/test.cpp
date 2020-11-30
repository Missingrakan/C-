#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

template<size_t N>
class Bitset
{
	friend ostream& operator<<(ostream& out, const Bitset<10> &bt);
public:
	Bitset() : m_bit((N - 1) / 32 + 1), m_size(N)
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
	size_t m_size;
};

ostream& operator<<(ostream &out, const Bitset<10> &bt)
{
	cout << bt.m_bit[0] << endl;
	for (int i = 9; i >= 0; --i)
	{
		if (bt.m_bit[i / 32] & (0x01 << i))
			out << 1;
		else
			out << 0;
	}
	return out;
}

void main()
{
	Bitset<10> bt;
	cout << bt << endl;
	//0000 0001 00
	bt.set(2);
	bt.set(1);
	cout << bt.test(3) << endl;
	cout << bt.count() << endl;
}

/*
int main()
{
	bitset<10> bt(100);
	cout << bt << endl;			//00011 00100

	bt.flip();					//对bt中结果取反
	cout << bt << endl;

	bt.set(2);					//bt中第二位置1
	cout << bt << endl;			//11100 11111

	bt.set(3, 0);				//bt中第三位置0
	cout << bt << endl;			//11100 10111

	cout << bt.count() << endl;	//bt中比特位为1的个数
	cout << bt.any() << endl;	//
	//bt.reset();					//00000 00000
	//cout << bt.any() << endl;	//bt中是否有比特位为1

	cout << bt.test(3) << endl;	//判断bt中第三个比特位是否为1
	cout << bt.to_ulong() << endl;	//格式转换
	cout << ~bt << endl;

	return 0;
}
*/
/*
int main()
{
	vector<int> v;
	//v.resize(10);		//改变capacity && 改变有效元素个数size+初始化(默认初始化为0)
	v.reserve(10);		//只改变capacity不改变有效元素个数size
	v.insert(v.end(), 2, 5);
	return 0;
}
*/