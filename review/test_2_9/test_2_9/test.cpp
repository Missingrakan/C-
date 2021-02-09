#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//给定一组字符，使用原地算法将其压缩。
//压缩后的长度必须始终小于或等于原数组长度。
//数组的每个元素应该是长度为1?的字符（不是 int 整数类型）。
//在完成原地修改输入数组后，返回数组的新长度。

//输入：["a", "a", "b", "b", "c", "c", "c"]
//输出：返回 6 ，输入数组的前 6 个字符应该是：["a", "2", "b", "2", "c", "3"]
//说明："aa" 被 "a2" 替代。"bb" 被 "b2" 替代。"ccc" 被 "c3" 替代。


class Solution {
public:
	int compress(vector<char>& chars) {
		int n = chars.size();
		int cur = 0;

		//i遍历到重复元素的末尾，j不动，i-j就是重复元素个数
		for (int i = 0, j = 0; i < n; j = i) {
			while (i < n && chars[i] == chars[j]) {
				i++;
			}
			chars[cur++] = chars[j];
			if (i - j == 1) {
				continue;
			}
			string s = to_string(i - j);
			for (int t = 0; t < s.size(); t++) {
				chars[cur++] = s[t];
			}
		}
		return cur;
	}
};

void main()
{
	Solution s;
	vector<char> v = { 'a' };
	cout << s.compress(v) << endl;
}


int compress(vector<char>& chars) {
	if (chars.empty()) return 0;

	size_t j = 0;
	int cnt = 0;
	for (size_t i = 1; i <= chars.size(); i++) 
	{
		cnt++;
		if (i == chars.size() || chars[i] != chars[j]) 
		{
			j++;
			if (cnt != 1) 
			{
				string scnt = to_string(cnt);
				for (auto c : scnt) 
				{
					chars[j++] = c;
				}
			}

			if (i == chars.size())
				break;
			chars[j] = chars[i];
			cnt = 0;
		}
	}

	return j;
}


/*
//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
//说明：本题中，我们将空字符串定义为有效的回文串。

//示例 1:
//输入 : "A man, a plan, a canal: Panama"
//输出 : true
//示例 2 :
//输入 : "race a car"
//输出 : 

class Solution {
public:
	bool isPalindrome(string s) {
		string sgood;
		for (char ch : s) {
			if (isalnum(ch)) {
				sgood += tolower(ch);
			}
		}
		int n = sgood.size();
		int left = 0, right = n - 1;
		while (left < right) {
			if (sgood[left] != sgood[right]) {
				return false;
			}
			++left;
			--right;
		}
		return true;
	}
};

class Solution {
public:
	bool isPalindrome(string s) {
		string sgood;
		for (char ch : s) {
			if (isalnum(ch)) {
				sgood += tolower(ch);
			}
		}
		string sgood_rev(sgood.rbegin(), sgood.rend());
		return sgood == sgood_rev;
	}
};
*/

/*
class Solution {
private:
	int findFitstPosition(vector<int> &nums, int target) {
		int size = nums.size();
		int left = 0;
		int right = size - 1;
		while (left < right)
		{
			int mid = left + (right - left) / 2;
			if (nums[mid] < target)
				left = mid + 1;
			else if (nums[mid] == target)
				right = mid;
			else
				// nums[mid] > target
				right = mid - 1;
		}
		if (nums[left] != target)
			return -1;
		return left;
	}

	int findLastPosition(vector<int> &nums, int target) {
		int size = nums.size();
		int left = 0;
		int right = size - 1;
		while (left < right) {
			int mid = left + (right - left + 1) / 2;
			if (nums[mid] > target) {
				right = mid - 1;
			}
			else if (nums[mid] == target){
				left = mid;
			}
			else {
				// nums[mid] < target
				left = mid + 1;
			}
		}
		if (nums[left] != target) {
			return -1;
		}
		return left;
	}


public:
	vector<int> searchRange(vector<int> &nums, int target) {
		int size = nums.size();
		if (size == 0) {
			return{ -1, -1 };
		}
		int fitstPosition = findFitstPosition(nums, target);

		if (fitstPosition == -1) {
			return{ -1, -1 };
		}
		int lastPosition = findLastPosition(nums, target);
		return{ fitstPosition, lastPosition };
	}
};

void main()
{
	vector<int> v = { 5, 7, 7, 8, 10, 10};
	Solution s;
	s.searchRange(v, 8);
}
*/