#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。返回删除后的链表的头节点。
//题目保证链表中节点的值互不相同
//若使用 C 或 C++ 语言，你不需要 free 或 delete 被删除的节点

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

//输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

class Solution {
public:
	vector<int> output;
	vector<int> printNumbers(int n) {
		// 以下注释的前提：假设 n = 3
		if (n <= 0) 
			return vector<int>(0);
		string s(n, '0'); // s最大会等于999，即s的长度为n
		while (!overflow(s)) 
			inputNumbers(s);
		return output;
	}
	bool overflow(string& s)
	{
		// 本函数用于模拟数字的累加过程，并判断是否越界（即 999 + 1 = 1000，就是越界情况）
		bool isOverFlow = false;
		int carry = 0; // carry表示进位
		for (int i = s.length() - 1; i >= 0; --i)
		{
			int current = s[i] - '0' + carry; // current表示当前这次的操作
			if (i == s.length() - 1) 
				current++; // 如果i此时在个位，current执行 +1 操作
			if (current >= 10)
			{
				// 假如i已经在最大的那一位了，而current++之后>=10，说明循环到头了，即999 + 1 = 1000
				if (i == 0) 
					isOverFlow = true;
				else
				{
					// 只是普通进位，比如current从9变成10
					carry = 1;
					s[i] = current - 10 + '0';
				}
			}
			else
			{
				// 如 新s[i]的值，然后直接跳出循环，这样就可以回去执行inputNumbers函数了，即往output里添加元素
				s[i] = current + '0';
				break;
			}
		}
		return isOverFlow;
	}
	void inputNumbers(string s)
	{
		// 本函数用于循环往output中添加符合传统阅读习惯的元素。比如001，我们会添加1而不是001。
		bool isUnwantedZero = true; // 判断是否是不需要添加的0，比如001前面的两个0
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
		// 这个函数的执行机制我想了好久才弄明白，mark一下，对带有循环的递归有时候还挺绕的
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
		// 本函数与方法二的同名函数基本一样
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
			output.push_back(stoi(temp)); // 如果 s = "000"，则temp会是空，stoi无法执行，会报错
	}
};


//实现函数double Power(double base, int exponent)，
//求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。

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

//请实现一个函数，输入一个整数，输出该数二进制表示中 1 的个数。
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

			//此处移位负数可能会导致死循环
			n >>= 1;
		}
		return count;
	}
};
*/
