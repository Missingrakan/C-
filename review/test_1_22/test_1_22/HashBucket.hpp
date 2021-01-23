#pragma once

#include <vector>

#include "common.h"

template <class T>
struct HashNode
{
	HashNode(const T& x = T())
	: next(nullptr)
	, data(x)
	{}
	HashNode<T>* next;
	T data;
};

template<class T>
class DToIntDef
{
public:
	const T& operator()(const T& data)const
	{
		return data;
	}
};

class StrToInt
{
public:
	size_t BKDRHash(const char* str)const
	{
		size_t seed = 131;
		size_t hash = 0;
		while (*str)
		{
			hash = hash*seed + (*str++);
		}
		return (hash & 0x7FFFFFFF);
	}
};

template<class T, class KOFV, class DToInt = StrToInt>
class HashBucket;

template<class T, class KOFV, class DToInt>
struct HashBucketIterator
{
	typedef HashNode<T> Node;
	typedef HashBucketIterator<T, KOFV, DToInt> Self;

	HashBucketIterator(Node* pNode = nullptr, HashBucket<T, KOFV, DToInt>* ht = nullptr)
		: _pNode(pNode)
		, _ht(ht)
	{}

	T& operator*()
	{
		return _pNode->data;
	}

	T* operator->()
	{
		return &(operator*());
	}

	Self& operator++()
	{
		Next();
		return *this;
	}

	Self operator++(int)
	{
		Self temp(*this);
		Next();
		return temp;
	}

	bool operator!=(const Self& s)
	{
		return !(*this == s);
	}

	bool operator==(const Self& s)
	{
		return (_pNode == s._pNode) && (_ht == s._ht);
	}

	//�ҵ�ǰ����������һ��λ��
	void Next()
	{
		//1._pNode֮���нڵ�
		if (_pNode->next)
		{
			_pNode = _pNode->next;
		}
		else
		{
			//2.pNode�ǵ�ǰͰ�����һ���ڵ�----����ҪѰ����һ���ǿ�Ͱ
			size_t bucketCount = _ht->BucketCount();
			size_t bucketNo = _ht->HashFunc(_pNode->data, bucketCount) + 1;
			for (; bucketNo < bucketCount; ++bucketNo)
			{
				if (_ht->table[bucketNo])
				{
					_pNode = _ht->table[bucketNo];
					return;
				}
			}
			_pNode = nullptr;
		}
	}

	Node* _pNode;
	HashBucket<T, KOFV, DToInt>* _ht;
};


template<class T, class KOFV, class DToInt>
class HashBucket
{
	friend HashBucketIterator<T, KOFV, DToInt>;
	typedef HashNode<T> Node;
public:
	typedef HashBucketIterator<T, KOFV, DToInt> iterator;
public:
	HashBucket(size_t capacity = 10)
		: table(10)
		, _size(0)
	{}

	~HashBucket()
	{
		clear();
	}

	iterator begin()
	{
		// �ҷǿ�Ͱ
		for (size_t bucket = 0; bucket < table.capacity(); ++bucket)
		{
			if (table[bucket])
			{
				return iterator(table[bucket], this);
			}
		}

		return end();
	}

	iterator end()
	{
		return iterator(nullptr, this);
	}

	pair<iterator, bool> InsertUnique(const T& data)
	{
		_CheckCapacity();
		//1.ͨ����ϣ����ȷ��Ͱ��
		size_t bucketno = HashFunc(data, table.capacity());

		//2.���data�Ƿ���bucketnoͰ�д���
		Node* cur = table[bucketno];
		while (cur)
		{
			if (KOFV()(data) == KOFV()(cur->data))
			{
				return make_pair(iterator(cur, this), false);
			}

			cur = cur->next;
		}

		//3.����Ԫ��
		cur = new Node(data);
		cur->next = table[bucketno];
		table[bucketno] = cur;
		_size++;

		return make_pair(iterator(cur, this), true);
	}

	bool InsertEqual(const T& data)
	{
		size_t bucketno = HashFunc(data, table.capacity());

		Node* cur = new Node(data);
		cur->next = table[bucketno];
		table[bucketno] = cur;
		_size++;

		return true;
	}

	size_t EraseUnique(const T& data)
	{

	}

	size_t EraseEquel(const T& data)
	{
		return 0;
	}

	iterator find(const T& data)
	{
		size_t bucketno = HashFunc(data, table.capacity());

		Node* cur = table[bucketno];
		while (cur)
		{
			if (KOFV(data) == KOFV(cur->data))
				return iterator(cur, this);

			cur = cur->next;
		}

		return end();
	}

	size_t size()const
	{
		return _size;
	}

	bool empty()const
	{
		return _size == 0;
	}

	void PrintHashBucket()
	{
		for (size_t i = 0; i < table.capacity(); ++i)
		{
			cout << "[" << i << "]:";

			Node* cur = table[i];
			while (cur)
			{
				cout << cur->data << "--->";
				cur = cur->next;
			}

			cout << "NULL" << endl;
		}

		cout << "================================================" << endl;
	}

	void swap(HashBucket<T, KOFV, DToInt>& ht)
	{
		table.swap(ht.table);
		swap(_size, ht._size);
	}

	void clear()
	{
		for (size_t i = 0; i < table.capacity(); ++i)
		{
			Node* cur = table[i];
			while(cur)
			{
				table[i] = cur->next;
				delete cur;
				cur = table[i];
			}
		}

		_size = 0;
	}
public:
	size_t BucketCount()const
	{
		return table.capacity;
	}

	size_t BucketSize(size_t bucketno)const
	{
		if (bucket >= BucketCount())
			return 0;

		Node* cur = table[bucketno];
		size_t count = 0;
		while (cur)
		{
			count++;
			cur = cur->next;
		}

		return count;
	}

	size_t Bucket(const T& data)
	{
		return HashFunc(data, BucketCount());
	}
private:
	size_t HashFunc(const T& data, size_t capacity)
	{
		//DToInt dtoi;
		//return dtoi(data) % capacity;
		return DToInt()(KOFV()(data)) % capacity;
	}

	void _CheckCapacity()
	{
		if (_size == table.capacity())
		{
			vector<Node*> bucket(GetNextPrime(table.capacity()));

			//����Ͱ��ÿ�������еĽڵ�����ƶ�����Ͱ��
			for (size_t i = 0; i < table.capacity(); ++i)
			{
				Node* cur = table[i];
				while (cur)
				{
					//1.��Ҫ���ýڵ�Ӿ������в�����
					table[i] = cur->next;

					//2.��cur���뵽��Ͱ��
					//a.����ýڵ����¹�ϣͰ���ĸ�Ͱ��
					size_t bucketno = HashFunc(cur->data, bucket.capacity());

					//b.���ýڵ���뵽��Ͱ-----��ͷ��
					cur->next = bucket[bucketno];
					bucket[bucketno] = cur;

					//3.ȡͰ����һ���ڵ�
					cur = table[i];
				}
			}
			table.swap(bucket);
		}
	}
private:
	vector<Node*> table;
	size_t _size;
};
