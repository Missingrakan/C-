#pragma once

#include <vector>

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

	Self& operator++(int)
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

	//找当前迭代器的下一个位置
	void Next()
	{
		//1._pNode之后有节点
		if (_pNode->next)
		{
			_pNode = _pNode->next;
		}
		else
		{
			//2.pNode是当前桶中最后一个节点----》需要寻找下一个非空桶
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
	typedef HashNode<T> Node;
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
		// 找非空桶
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


private:
	std::vector<Node*> table;
	size_t _size;
};
