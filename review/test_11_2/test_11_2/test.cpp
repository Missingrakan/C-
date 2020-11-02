#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//�������������ͷָ���һ��Ҫɾ���Ľڵ��ֵ������һ������ɾ���ýڵ㡣����ɾ����������ͷ�ڵ㡣
//��Ŀ��֤�����нڵ��ֵ������ͬ
//��ʹ�� C �� C++ ���ԣ��㲻��Ҫ free �� delete ��ɾ���Ľڵ�

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
	ListNode* deleteNode(ListNode* head, int val) {
		if (head == NULL)
			return NULL;

		if (head->val == val)
			return head->next;

		ListNode* prev, *tmp = head;
		while (tmp != NULL && tmp->val != val)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		prev->next = tmp->next;
		return head;
	}
};

//�������� n����˳���ӡ���� 1 ������ n λʮ���������������� 3�����ӡ�� 1��2��3 һֱ������ 3 λ�� 999��

class Solution {
public:
	vector<int> output;
	vector<int> printNumbers(int n) {
		// ����ע�͵�ǰ�᣺���� n = 3
		if (n <= 0) 
			return vector<int>(0);
		string s(n, '0'); // s�������999����s�ĳ���Ϊn
		while (!overflow(s)) 
			inputNumbers(s);
		return output;
	}
	bool overflow(string& s)
	{
		// ����������ģ�����ֵ��ۼӹ��̣����ж��Ƿ�Խ�磨�� 999 + 1 = 1000������Խ�������
		bool isOverFlow = false;
		int carry = 0; // carry��ʾ��λ
		for (int i = s.length() - 1; i >= 0; --i)
		{
			int current = s[i] - '0' + carry; // current��ʾ��ǰ��εĲ���
			if (i == s.length() - 1) 
				current++; // ���i��ʱ�ڸ�λ��currentִ�� +1 ����
			if (current >= 10)
			{
				// ����i�Ѿ���������һλ�ˣ���current++֮��>=10��˵��ѭ����ͷ�ˣ���999 + 1 = 1000
				if (i == 0) 
					isOverFlow = true;
				else
				{
					// ֻ����ͨ��λ������current��9���10
					carry = 1;
					s[i] = current - 10 + '0';
				}
			}
			else
			{
				// �� ��s[i]��ֵ��Ȼ��ֱ������ѭ���������Ϳ��Ի�ȥִ��inputNumbers�����ˣ�����output�����Ԫ��
				s[i] = current + '0';
				break;
			}
		}
		return isOverFlow;
	}
	void inputNumbers(string s)
	{
		// ����������ѭ����output����ӷ��ϴ�ͳ�Ķ�ϰ�ߵ�Ԫ�ء�����001�����ǻ����1������001��
		bool isUnwantedZero = true; // �ж��Ƿ��ǲ���Ҫ��ӵ�0������001ǰ�������0
		string temp = "";
		for (int i = 0; i<s.length(); ++i)
		{
			if (isUnwantedZero && s[i] != '0') 
				isUnwantedZero = false;
			if (!isUnwantedZero) 
				temp += s[i];
		}
		output.push_back(stoi(temp));
	}
};

class Solution {
public:
	vector<int> output;
	vector<int> printNumbers(int n) {
		if (n <= 0) 
			return vector<int>(0);
		string s(n, '0');
		for (int i = 0; i <= 9; ++i)
		{
			s[0] = i + '0';
			permutation(s, s.length(), 1);
		}
		return output;
	}
	void permutation(string& s, int length, int pos)
	{
		// ���������ִ�л��������˺þò�Ū���ף�markһ�£��Դ���ѭ���ĵݹ���ʱ��ͦ�Ƶ�
		if (pos == length)
		{
			inputNumbers(s);
			return;
		}
		for (int i = 0; i <= 9; ++i)
		{
			s[pos] = i + '0';
			permutation(s, length, pos + 1);
		}
	}
	void inputNumbers(string s)
	{
		// �������뷽������ͬ����������һ��
		bool isUnwantedZero = true;
		string temp = "";
		for (int i = 0; i<s.length(); ++i)
		{
			if (isUnwantedZero && s[i] != '0') 
				isUnwantedZero = false;
			if (!isUnwantedZero) 
				temp += s[i];
		}
		if (temp != "") 
			output.push_back(stoi(temp)); // ��� s = "000"����temp���ǿգ�stoi�޷�ִ�У��ᱨ��
	}
};


//ʵ�ֺ���double Power(double base, int exponent)��
//��base��exponent�η�������ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ������⡣

class Solution {
public:
	double myPow(double x, int n) {
		if (x == 1 || n == 0) 
			return 1;
		double ans = 1;
		long num = n;
		if (n < 0){
			num = -num;
			x = 1 / x;
		}
		while (num){
			if (num & 1) ans *= x;
			x *= x;
			num >>= 1;
		}
		return ans;
	}
};

double myPow(double x, int n) {
	if (x == 1 || n == 0)
		return 1;
	double ans = 1;
 	long num = n;
	if (n < 0){
		num = -num;
		x = 1 / x;
	}
	while (num){
		if (num & 1) 
			ans *= x;
		x *= x;
		num >>= 1;
	}
	return ans;
}

int main()
{
	double ret = myPow(3, 4);
	return 0;
}

//��ʵ��һ������������һ��������������������Ʊ�ʾ�� 1 �ĸ�����
/*
class Solution {
public:
	//int hammingWeight(uint32_t n) {
	int hammingWeight(int n) {
		int count = 0;
		while (n)
		{
			++count;
			n = (n - 1)&n;
		}
		return count;
	}
};
*/
/*
class Solution {
public:
	int hammingWeight(uint32_t n) {
	int count = 0;
	unsigned int flag = 1;
	while(flag)
	{
		if(n&flag)
			count++;

		flag = flag << 1;
	}
	return count;
	}
};
*/
/*
class Solution {
public:
	int hammingWeight(uint32_t n) {
		int count = 0;
		while(n)
		{
			if(n&1)
				count++;

			//�˴���λ�������ܻᵼ����ѭ��
			n >>= 1;
		}
		return count;
	}
};
*/
