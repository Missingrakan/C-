#define _CRT_SECURE_NO_WARNINGS 1

//��һ������Ϊ n ������ nums ����������ֶ��� 0��n - 1 �ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡�
//
//ʾ�� 1��
//���룺
//[2, 3, 1, 0, 2, 5, 3]
//�����2 �� 3

//���ƣ�
//2 <= n <= 100000

class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		set<int> s;
		for (size_t i = 0; i < nums.size(); ++i)
		{
			auto it = s.insert(nums[i]);
			if (!it.second)
				return nums[i];
		}

		return -1;
	}
};
/*
class Solution {
public:
int findRepeatNumber(vector<int>& nums) {
vector<int> v(nums);
sort(v.begin(), v.end());

for(size_t i=0; i != v.size()-1; ++i)
{
if(v[i] == v[i+1])
return v[i];
}

return -1;
}
};
*/
/*
class Solution {
public:
int findRepeatNumber(vector<int>& nums) {
vector<int> v(nums);
sort(v.begin(), v.end());

for(auto it = v.begin(); it != v.end(); ++it)
{
if(*it == *(it+1))
return *it;
}

return -1;
}
};
*/
/*
class Solution {
public:
int findRepeatNumber(vector<int>& nums) {
vector<int> count;
count.resize(100000);
for(size_t i = 0; i < nums.size(); ++i)
{
count[nums[i]]++;
}

for(size_t i = 0; i < nums.size(); ++i)
{
if(count[i] >= 2)
return i;
}

return -1;
}
};
*/

//��һ�� n * m �Ķ�ά�����У�ÿһ�ж����մ����ҵ�����˳������
//ÿһ�ж����մ��ϵ��µ�����˳�����������һ��������
//����������һ����ά�����һ���������ж��������Ƿ��и�������

class Solution {
public:
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		int row = matrix.size() - 1;
		int col = 0;
		while (row >= 0 && col < matrix[0].size())
		{
			if (matrix[row][col] < target)
				col++;
			else if (matrix[row][col] > target)
				row--;
			else
				return true;
		}
		return false;
	}
};

//��ʵ��һ�����������ַ��� s �е�ÿ���ո��滻��"%20"��

//ʾ�� 1��
//
//���룺s = "We are happy."
//�����"We%20are%20happy."

class Solution {
public:
	string replaceSpace(string s) {
		int count = 0, len = s.size();
		for (auto e : s)
		{
			if (e == ' ')
				count++;
		}

		s.resize(len + 2 * count);       //' ' ��Ϊ ��%20�� �൱�����������ֽ�

		for (int i = len - 1, j = s.size() - 1; i < j; --i, --j)
		{
			if (s[i] != ' ')
				s[j] = s[i];
			else
			{
				s[j] = '0';
				s[j - 1] = '2';
				s[j - 2] = '%';
				j -= 2;
			}
		}
		return s;
	}
};
/*
class Solution {
public:
	string replaceSpace(string s) {
	if(s.empty())
		return s;
	string str = "";

	for(int i = 0; i != s.size(); ++i)
	{
		if(s[i] == ' ')
			str += "%20";
		else
			str += s[i];
	}

	return str;
	}
};
*/

//����һ�������ͷ�ڵ㣬��β��ͷ����������ÿ���ڵ��ֵ�������鷵�أ���
//
//ʾ�� 1��
//
//���룺head = [1, 3, 2]
//�����[2, 3, 1]

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

class Solution {
public:
	vector<int> reversePrint(ListNode* head) {
		vector<int> v;
		stack<int> st;

		while (head != NULL)
		{
			st.push(head->val);
			head = head->next;
		}

		while (!st.empty())
		{
			v.push_back(st.top());
			st.pop();
		}
		return v;
	}
};

/*
class Solution {
public:
vector<int> reversePrint(ListNode* head) {
	vector<int> v;

	while(head != NULL)
	{
		v.push_back(head->val);
		head = head->next;
	}
	reverse(v.begin(),v.end());
	return v;
	}
};
*/