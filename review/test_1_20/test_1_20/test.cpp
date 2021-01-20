#define _CRT_SECURE_NO_WARNINGS 1

//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//例如输入一个长度为9的数组{ 1, 2, 3, 2, 2, 2, 5, 4, 2 }。
//由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		std::unordered_map<int, int> match;
		for (const int val : numbers)
			++match[val];

		for (const int val : numbers)
		{
			if (match[val] > numbers.size() / 2)
				return val;
		}
		return 0;
	}
};


/*
class Solution {
public:
int MoreThanHalfNum_Solution(vector<int> numbers) {
		if(numbers.empty())
			return 0;

		sort(numbers.begin(), numbers.end());

		int size = numbers.size();
		int res = numbers[size/2];
		int count = 0;

		for(int i = 0; i < size; ++i)
		{
			if(numbers[i] == res)
				count++;
		}

		return (count > size/2) ? res : 0;
	}
};
*/

/*
//读入一个字符串str，输出字符串str中的连续最长的数字串
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;

	string res = "", tmp = "";

	//此处取等是为了保证最后一次更新
	for (int i = 0; i <= str.size(); ++i)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			tmp += str[i];
		}
		else
		{
			if (tmp.size()>res.size())
				res = tmp;
			else
				tmp.clear();
		}
	}

	cout << res << endl;
	return 0;
}
*/

/*
//将一句话的单词进行倒置，标点不倒置。比如 I like beijing. 经过函数后变为：beijing. like I
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string str1, str2;
	cin >> str1;
	while (cin >> str2)
		str1 = str2 + " " + str1;
	cout << str1 << endl;
	return 0;
}


int main()
{
	string str;
	getline(cin, str);

	reverse(str.begin(), str.end());

	auto start = str.begin();
	while (start != str.end())
	{
		auto end = start;
		while ((end != str.end()) && *end != ' ')
			++end;

		reverse(start, end);

		if (end != str.end())
			start = end + 1;
		else
			start = end;
	}

	cout << str << endl;

	return 0;
}
*/

/*
//牛牛定义排序子序列为一个数组中一段连续的子序列, 并且这段子序列是非递增或者非递减排序的。
//牛牛有一个长度为n的整数数组A, 他现在有一个任务是把数组A分为若干段排序子序列, 
//牛牛想知道他最少可以把这个数组分为几段排序子序列.
//如样例所示, 牛牛可以把数组A划分为[1, 2, 3]和[2, 2, 1]两个排序子序列, 至少需要划分为2个排序子序列, 所以输出2

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> v;
	v.resize(n + 1);
	v[n] = 0;
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int i = 0, count = 0;
	while (i < n)
	{
		//非递减子序列
		if (v[i] < v[i + 1])
		{
			while (i < n && v[i] <= v[i + 1])
				i++;
			count++;
			i++;
		}
		else if (v[i] == v[i + 1])
		{
			i++;
		}
		//非递增子序列
		else
		{
			while (i < n && v[i] >= v[i + 1])
				i++;
			count++;
			i++;
		}
	}

	cout << count << endl;

	return 0;
}
*/