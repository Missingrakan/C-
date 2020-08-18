#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int PRIMECOUNT = 28;
const size_t primeList[PRIMECOUNT] =
{
	53ul, 97ul, 193ul, 389ul, 769ul,
	1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
	49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
	1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
	50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
	1610612741ul, 3221225473ul, 4294967291ul
};
size_t GetNextPrime(size_t prime)
{
	size_t i = 0;
	for (; i < PRIMECOUNT; ++i)
	{
		if (primeList[i] >= prime)
			return primeList[i];
	}
	return primeList[i];
}
//////////////////////////////////////////////////////////////////
template<class V>
struct HashBucketNode
{
	HashBucketNode(const V& data) : _pNext(nullptr), _data(data)
	{}
	HashBucketNode<V>* _pNext;
	V _data;
};
template<class V>
class HashBucket
{
	typedef HashBucketNode<V> Node;
	typedef Node* PNode;
public:
	HashBucket(size_t capacity = 3) :_size(0)
	{
		_ht.resize(GetNextPrime(capacity), nullptr);
	}
public:
	PNode* Insert(const V& data)
	{
		//1.计算元素所在的桶号
		size_t bucketNo = HashFunc(data);
		//2.检测该元素是否在桶中
		PNode pCur = _ht[bucketNo];
		while (pCur)
		{
			if (pCur->_data == data)
				return pCur;
			pCur = pCur->_pNext;
		}
		//3.插入新元素
		pCur = new Node(data);
		pCur->_pNext = _ht[bucketNo];
		_ht[bucketNo] = pCur;
		_size++;
		return pCur;
	}

private:
	vector<PNode*> _ht;
	size_t _size;		//哈希表中有效元素的个数
};


//enum State{EMPTY,EXIST,DELETE};
//template<class K,class V>
//class HashTable
//{
//	struct Elem
//	{
//		pair<K, V> _val;		//key-value
//		State _state;			//标记
//	};
//public:
//	HashTable(size_t capacity = 3) : _ht(capacity), _size(0)
//	{
//		for (size_t i = 0; i < capacity; ++i)
//			_ht[i]._state = EMPTY;
//	}
//	bool Insert(const pair<K, V>& val)
//	{
//		// 检测哈希表底层空间是否充足
//		_CheckCapacity();
//		size_t hashAddr = HashFunc(val.first);
//		while (_ht[hashAddr]._state != EMPTY)
//		{
//			if (_ht[hashAddr]._state == EXIST && _ht[hashAddr]._val.first == val.first)
//				return false;
//			hashAddr++;
//			if (hashAddr == _ht.capacity())
//				hashAddr = 0;
//		}
//		//插上元素
//		_ht[hashAddr]._state = EXIST;
//		_ht[hashAddr]._val = val;
//		_size++;
//		return true;
//	}
//	int Find(const K& key)
//	{
//		size_t hashAddr = HashFunc(key);
//		while (_ht[hashAddr]._state != EMPTY)
//		{
//			if (_ht[hashAddr]._state == EXIST && _ht[hashAddr]._val.first == key)
//				return hashAddr;
//			hashAddr++;
//			if (hashAddr == _ht.capacity())
//				hashAddr = 0;
//		}
//		return hashAddr;
//	}
//	bool Erase(const K& val)
//	{
//		int index = Find(Key);
//		if (-1 != Index)
//		{
//			_ht[index]._state = DELETE;
//			_size--;
//			return true;
//		}
//		return false;
//	}
//	size_t Size()const
//	{
//		return _size;
//	}
//	bool Empty()const
//	{
//		return _size == 0;
//	}
//	void Swap(HashTable<K, V>& ht)
//	{
//		swap(ht._ht, _ht);
//		swap(ht._size, _size);
//	}
//private:
//	size_t HashFunc(const K& key)
//	{
//		return key % _ht.capacity();
//	}
//	void _CheckCapacity()
//	{
//		if (_size * 10 / _ht.capacity() >= 7)
//		{
//			HashTable<K, V> newHt(_ht.capacity() + 2);
//			for (size_t i = 0; i < _ht.capacity(); ++i)
//			{
//				if (_ht[i]._state == EXIST)
//					newHt.Insert(_ht[i]._val);
//			}
//			Swap(newHt);
//		}
//	}
//private:
//	vector<Elem> _ht;
//	size_t _size;
//};
//
//void main()
//{
//	HashTable<int, string> ht(13);
//	ht.Insert(make_pair(1, "abc"));
//	ht.Insert(make_pair(3, "xyz"));
//	ht.Insert(make_pair(2, "hjk"));
//	ht.Insert(make_pair(14, "lmn"));
//	int index = ht.Find(14);  // 14 % 13 =1
//
//	//HashTable<int, string> ht(13);
//	//ht.Insert(make_pair(1, "abc"));
//	//ht.Insert(make_pair(3, "xyz"));
//	//ht.Insert(make_pair(2, "hjk"));
//	//ht.Insert(make_pair(14, "lmn"));
//}