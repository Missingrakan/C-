#define _CRT_SECURE_NO_WARNINGS 1

//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//你可以假设数组是非空的，并且给定的数组总是存在多数元素。
//
//示例 1 :
//
//输入 : [1, 2, 3, 2, 2, 2, 5, 4, 2]
//输出 : 2

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		unordered_map<int, int> match;
		int len = nums.size();
		int res;
		if (len == 1 || len == 2)
			return nums[0];

		for (size_t i = 0; i < len; ++i)
		{
			match[nums[i]]++;
			if (match[nums[i]] >(len / 2))
			{
				res = nums[i];
				break;
			}
		}
		return res;
	}
};

//输入整数数组 arr ，找出其中最小的 k 个数。例如，
//输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

//示例 1：

//输入：arr = [3, 2, 1], k = 2
//输出：[1, 2] 或者[2, 1]
//示例 2：

//输入：arr = [0, 1, 2, 1], k = 1
//输出：[0]


class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		if (arr.empty() || k == 0)
			return{};

		vector<int> res(k);
		priority_queue<int> max_heap;

		for (int i = 0; i < k; ++i)
			max_heap.push(arr[i]);

		for (int i = k; i < arr.size(); ++i)
		{
			if (arr[i] < max_heap.top())
			{
				max_heap.pop();
				max_heap.push(arr[i]);
			}

		}

		for (int i = 0; i < k; ++i)
		{
			res[i] = max_heap.top();
			max_heap.pop();
		}
		return res;
	}
};

/*
class Solution {
public:
vector<int> getLeastNumbers(vector<int>& arr, int k) {
		if(arr.empty() || k == 0)
			return {};

		vector<int> res;
		sort(arr.begin(), arr.end());

		for(int i = 0; i < k; ++i)
		{
			res.push_back(arr[i]);
		}
		return res;
	}
};
*/

/*
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int n = nums.size();
		vector<int> newArr(n);
		for (int i = 0; i < n; ++i) {
			newArr[(i + k) % n] = nums[i];
		}
		nums.assign(newArr.begin(), newArr.end());
	}
};


class Solution {
public:
	void reverse(vector<int>& nums, int start, int end) {
		while (start < end) {
			swap(nums[start], nums[end]);
			start += 1;
			end -= 1;
		}
	}

	void rotate(vector<int>& nums, int k) {
		k %= nums.size();
		reverse(nums, 0, nums.size() - 1);
		reverse(nums, 0, k - 1);
		reverse(nums, k, nums.size() - 1);
	}
};

*/