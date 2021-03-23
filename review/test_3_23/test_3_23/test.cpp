#include <iostream>

using namespace std;

//给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

class Solution {
public:
	void reverse(vector<int>&nums, int left, int right)
	{
		while (left < right)
		{
			swap(nums[left++], nums[right--]);
		}
	}
	void rotate(vector<int>& nums, int k) {
		int sz = nums.size();
		k %= sz;
		reverse(nums, 0, sz - 1);
		reverse(nums, 0, k - 1);
		reverse(nums, k, sz - 1);
	}

	/*
	void rotate(vector<int>& nums, int k) {
	int sz = nums.size();
	vector<int> tmp(sz);
	k %= sz;
	for(int i = 0; i < sz; ++i)
	tmp[(i+k)%sz] = nums[i];

	nums.assign(tmp.begin(), tmp.end());
	}
	*/
};

//插入排序

void insertSort(int arr[], int sz)
{
	for (int i = 1; i < sz; ++i)
	{
		int value = arr[i];
		int end = i - 1;

		while (end >= 0 && value < arr[end])
		{
			arr[end + 1] = arr[end];
			end--;
		}

		arr[end+1] = value;
	}
}

void shellSort(int arr[], int sz)
{
	int gap = sz;

	while (gap > 1)
	{
		gap = gap / 3 + 1;

		for (int i = gap; i < sz; ++i)
		{
			int value = arr[i];
			int end = i - gap;

			while (i < sz && value < arr[end])
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}

			arr[end + gap] = value;
		}
	}
}

void printArray(int ar[], int sz)
{
	for (int i = 0; i < sz; ++i)
		cout << ar[i] << " ";
	cout << endl;
}

int main()
{
	int ar[10] = { 1, 5, 3, 8, 4,  9, 7, 2, 6, 0 };
	printArray(ar, 10);
	//insertSort(ar, 10);
	shellSort(ar, 10);
	printArray(ar, 10);
}

/*
// 默认构造函数
class Date
{
public:
	Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
// 以下测试函数能通过编译吗？
void Test()
{
	Date d1;
}
*/