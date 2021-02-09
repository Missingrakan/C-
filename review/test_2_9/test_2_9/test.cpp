#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//����һ���ַ���ʹ��ԭ���㷨����ѹ����
//ѹ����ĳ��ȱ���ʼ��С�ڻ����ԭ���鳤�ȡ�
//�����ÿ��Ԫ��Ӧ���ǳ���Ϊ1?���ַ������� int �������ͣ���
//�����ԭ���޸���������󣬷���������³��ȡ�

//���룺["a", "a", "b", "b", "c", "c", "c"]
//��������� 6 �����������ǰ 6 ���ַ�Ӧ���ǣ�["a", "2", "b", "2", "c", "3"]
//˵����"aa" �� "a2" �����"bb" �� "b2" �����"ccc" �� "c3" �����


class Solution {
public:
	int compress(vector<char>& chars) {
		int n = chars.size();
		int cur = 0;

		//i�������ظ�Ԫ�ص�ĩβ��j������i-j�����ظ�Ԫ�ظ���
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
//����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��
//˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���

//ʾ�� 1:
//���� : "A man, a plan, a canal: Panama"
//��� : true
//ʾ�� 2 :
//���� : "race a car"
//��� : 

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