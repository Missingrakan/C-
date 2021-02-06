#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int pivotIndex(vector<int>& nums) {
		int sumr = 0, suml = 0, n = nums.size();
		if (n == 0 || n == 2)    return -1;
		if (n == 1)  return 0;

		for (const auto num : nums)  sumr += num;
		for (int i = 0; i<n; i++) {
			if (suml == sumr - nums[i])
				return i;
			suml += nums[i];
			sumr -= nums[i];
		}
		return -1;
	}
};

//����һ���Ǹ��������� A������һ�����飬�ڸ������У�?A ������ż��Ԫ��֮�������������Ԫ�ء�
//����Է���������������κ�������Ϊ�𰸡�

//ʾ����
//
//���룺[3, 1, 2, 4]
//�����[2, 4, 3, 1]
//���[4, 2, 3, 1]��[2, 4, 1, 3] ��[4, 2, 1, 3] Ҳ�ᱻ���ܡ�

vector<int> sortArrayByParity(vector<int>& A) {
	int start = 0;
	int end = A.size() - 1;

	while (start <= end)
	{
		//������
		if (start < A.size() - 1 && (A[start] & 1) == 0)
			start++;

		//��ż��
		else if (end >= 0 && (A[end] & 1) == 1)
			end--;

		else
			swap(A[start++], A[end--]);
	}

	return A;
}

void main()
{
	vector<int> v = { 3, 1, 2, 4 };
	sortArrayByParity(v);
}

/*
//����һ���ַ���?S������?����ת��ġ�?�ַ��������в�����ĸ���ַ���������ԭ�أ���������ĸ��λ�÷�����ת��
//
//���룺"a-bC-dEf-ghIj"
//�����"j-Ih-gfE-dCba"
//
//���룺"Test1ng-Leet=code-Q!"
//�����"Qedo1ct-eeLg=ntse-T!"


class Solution {
public:
	string reverseOnlyLetters(string S) {
		int begin = 0, end = S.length() - 1;
		while (begin<end)
		{
			if (!isalpha(S[begin]))
				begin++;
			if (!isalpha(S[end]))
				end--;
			if (isalpha(S[begin]) && isalpha(S[end]))
				swap(S[begin++], S[end--]);
		}
		return S;
	}
};
*/

/*
//����һ���� �ǵݼ�˳�� ������������� nums������ ÿ�����ֵ�ƽ�� ��ɵ������飬Ҫ��Ҳ�� �ǵݼ�˳�� ����
class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		vector<int> tmp;
		for (auto e : nums)
			tmp.push_back(e*e);

		sort(tmp.begin(), tmp.end());

		return tmp;
	}
};

class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		vector<int> res;
		res.resize(nums.size());
		int k = nums.size() - 1;
		int i = 0, j = k;
		while (i <= j)
		{
			//ȷ������ƽ������λ��
			if (nums[i] * nums[i] < nums[j] * nums[j])
			{
				res[k--] = nums[j] * nums[j];
				j--;;
			}
			else
			{
				res[k--] = nums[i] * nums[i];
				i++;
			}
		}

		return res;
	}
};
*/

/*
//�����������ʹ�ü���������������?name��ż�����ڼ����ַ�?c?ʱ���������ܻᱻ���������ַ����ܱ����� 1 �λ��Ρ�
//�㽫�������������ַ�?typed���������Ӧ�Ŀ�����������ѵ����֣�����һЩ�ַ����ܱ�����������ô�ͷ���?True��

class Solution {
public:
	bool isLongPressedName(string name, string typed) {
		int i = 0, j = 0;
		while (j < typed.length()) {
			if (i < name.length() && name[i] == typed[j]) {
				i++;
				j++;
			}
			else if (j > 0 && typed[j] == typed[j - 1]) {
				j++;
			}
			else {
				return false;
			}
		}
		return i == name.length();
	}
};
*/

/*
//����һ���������飬�ж��Ƿ�����ظ�Ԫ�ء�
//�������һֵ�������г����������Σ��������� true �����������ÿ��Ԫ�ض�����ͬ���򷵻� false ��

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		for (int i = 0; i < n - 1; i++) {
			if (nums[i] == nums[i + 1]) {
				return true;
			}
		}
		return false;
	}
};

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> s;
		for (int x : nums) {
			if (s.find(x) != s.end()) {
				return true;
			}
			s.insert(x);
		}
		return false;
	}

	bool containsDuplicate(vector<int>& nums) {

		return nums.size() > unordered_set<int>(nums.begin(), nums.end()).size();
		//���ԭ����Ĵ�С>���ϵĴ�С����˵�������ظ�Ԫ��
	}
};

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_map<int, int> map;

		for (auto&e : nums)
		{
			if (map[e]++)
				return true;
		}
		return false;
	}
};
*/