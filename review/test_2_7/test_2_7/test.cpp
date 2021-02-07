#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <functional>

using namespace std;

//���������������ַ������������ǵĺͣ��ö����Ʊ�ʾ����
//����Ϊ �ǿ� �ַ�����ֻ�������� 1 �� 0��
class Solution {
public:
	string addBinary(string a, string b) {
		string ans;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		int n = max(a.size(), b.size()), carry = 0;
		for (size_t i = 0; i < n; ++i) {
			carry += i < a.size() ? (a.at(i) == '1') : 0;
			carry += i < b.size() ? (b.at(i) == '1') : 0;
			ans.push_back((carry % 2) ? '1' : '0');
			carry /= 2;
		}

		if (carry) {
			ans.push_back('1');
		}
		reverse(ans.begin(), ans.end());

		return ans;
	}
};

/*
//����һ���������� nums?��һ������Ŀ��ֵ target�������ڸ��������ҳ� ��ΪĿ��ֵ ����?����?���������������ǵ������±ꡣ
//����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ�ز���ʹ�����顣
//����԰�����˳�򷵻ش𰸡�

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> hashtable;
		for (int i = 0; i < nums.size(); ++i)
		{
			auto it = hashtable.find(target - nums[i]);
			if (it != hashtable.end())
			{
				return{ it->second, i };
			}
			hashtable[nums[i]] = i;
		}
		return{};
	}
};

class Solution {
public:
vector<int> twoSum(vector<int>& nums, int target) {
		int n = nums.size();
		for(int i = 0; i < n; ++i)
		{
			int j;
			for(j = i+1; j < n; ++j)
			{
				if(nums[i] + nums[j] == target)
				return {i, j};
			}
		}
		return {};
	}
};
*/

//����һ���ǿ����飬���ش������� ��������� ����������ڣ��򷵻���������������

/*
int thirdMax(vector<int>& nums) {
	set<int> visited;
	priority_queue<int, vector<int>, greater<int>> topThree;
	for (const auto& num : nums) {
		if (visited.count(num)) {
			continue;
		}
		visited.insert(num);
		topThree.push(num);
		if (topThree.size() > 3) {
			topThree.pop();
		}
	}

	if (topThree.size() == 3) {
		return topThree.top();
	}

	int largest;
	while (!topThree.empty()) {
		largest = topThree.top();
		topThree.pop();
	}

	return largest;
}

void main()
{
	vector<int> v = { 5, 7, 8, 9, 6, 4 };
	int a = thirdMax(v);
}


class Solution3 {
public:
	int thirdMax(vector<int>& nums) {
		set<int> topThree;
		for (const auto& num : nums) {
			topThree.insert(num);
			if (topThree.size() > 3) {
				topThree.erase(topThree.begin());
			}
		}

		assert(!topThree.empty());
		return topThree.size() < 3 ? *topThree.rbegin() : *topThree.begin();
	}
};
*/

/*
//����һ���� ���� ��ɵ� �ǿ� ��������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��
//���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢�������֡�
//����Լ���������� 0 ֮�⣬��������������㿪ͷ��

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int sz = digits.size();
		for (int i = sz - 1; i >= 0; --i)
		{
			digits[i]++;
			//��ǰλ�ӵ�10Ҫ������λ������ѭ��
			if (digits[i] == 10)
				digits[i] = 0;

			//��������λ��ֱ�ӷ���
			else
				return digits;
		}

		//��ѭ����δ���أ�˵����һֱ������λ(999..99+1���)����begin()λ�ò���1����
		digits.insert(digits.begin(), 1);
		return digits;
	}
};

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		//ֻ����ԭ�����в�����
		//������Ӹ�λ���λ��������ǰλֵ��Ϊ9��������ֵΪ0������Ϊ9����ֵ + 1��break�˳�ѭ����
		//����ж�һ�������������99..9 + 1������Ϊ�������������������ѭ������������λ��Ϊ0��ֻ����λ��Ϊ1���ٽ�һ��0ѹ������β�����ɡ�

		int n = digits.size();
		for (int i = n - 1; i >= 0; --i)
		{
			if (digits[i] == 9){
				digits[i] = 0;
			}
			else{
				digits[i] += 1;
				break;
			}
		}
		if (digits[0] == 0){
			digits[0] = 1;
			digits.push_back(0);
		}
		return digits;
	}
};
*/