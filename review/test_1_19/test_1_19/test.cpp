#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

/*
//输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。例如，
//输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);

	int hashtable[256] = { 0 };
	for (const auto&e : str2)
		hashtable[e]++;

	string tmp;
	for (const auto&e : str1)
	{
		if (hashtable[e] == 0)
			tmp += e;
	}

	cout << tmp << endl;

	return 0;
}
*/

/*
//牛牛举办了一次编程比赛, 参加比赛的有3*n个选手, 每个选手都有一个水平值a_i.
//现在要将这些选手进行组队, 一共组成n个队伍, 即每个队伍3人.牛牛发现队伍的水平值等于该队伍队员中第二高水平值。

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		long long sum = 0;
		vector<int> v;
		v.resize(3 * n);
		for (int i = 0; i < 3 * n; ++i)
			cin >> v[i];

		sort(v.begin(), v.end());

		for (int i = n; i <= 3 * n - 2; i += 2)
			sum += v[i];

		cout << sum << endl;
	}
	return 0;
}
*/

/*
//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它
//将会被按顺序插入的位置, 你可以假设数组中无重复元素
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		//二分查找
		int sz = nums.size();
		int left = 0;
		int right = sz - 1;
		int mid, pos = sz;
		while (left <= right)
		{
			mid = left + (right - left) / 2;
			if (nums[mid] >= target)
			{
				pos = mid;
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}

		return pos;
	}
};
*/

/*
//给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int size = nums.size();
		for (int i = 0; i < size; i++) {
			if (nums[i] == val) { // 发现需要移除的元素，就将数组集体向前移动一位
				for (int j = i + 1; j < size; j++) {
					nums[j - 1] = nums[j];
				}
				i--; // 因为下表i以后的数值都向前移动了一位，所以i也向前移动一位
				size--; // 此时数组的大小-1
			}
		}
		return size;

	}
};

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.empty()) return 0;
		int n = nums.size();

		int cur = 0;
		for (int i = 0; i < n; i++) {
			//找不是删除元素的值存放在cur处
			if (nums[i] != val) {
				nums[cur] = nums[i];
				cur++;
			}
		}
		return cur;
	}
};
*/

/*
int main()
{
	int a;
	a = 'A' + 1.6;
	//cout << typeid(a).name() << endl;
	cout << a << endl;
	return 0;
}
*/