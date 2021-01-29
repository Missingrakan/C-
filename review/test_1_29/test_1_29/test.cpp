#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;



//请编写一个参数解析程序，实现将命令行各个参数解析出来。
//解析规则：
//
//1.参数分隔符为空格
//2.对于用“”包含起来的参数，如果中间有空格，不能解析为多个参数。比如在命令行输入xcopy / s “C : \program files” “d : \”时，参数仍然是4个，第3个参数应该是字符串C : \program files，而不是C : \program，注意输出参数时，需要将“”去掉，引号不存在嵌套情况。
//3.参数不定长
//4.输入由用例保证，不会出现不符合要求的输入


int main()
{
	string str;
	while (getline(cin, str))
	{
		//统计参数个数
		int count = 0;
		int sz = str.size();
		for (int i = 0; i < sz; ++i)
		{
			if (str[i] == ' ')
				count++;
			//对”“中的字符特殊处理
			if (str[i] == '"')
			{
				do{
					i++;
				} while (str[i] != '"');
			}
		}

		cout << count + 1 << endl;

		int flag = 1;
		for (int i = 0; i < sz; ++i)
		{
			if (str[i] == '"')
				flag ^= 1;
			if (str[i] != ' ' && str[i] != '"')
				cout << str[i];
			//双引号内的空格打印
			if (str[i] == ' ' && (!flag))
				cout << str[i];
			//双引号外的空格换行
			if (str[i] == ' ' && flag)
				cout << endl;
		}
		cout << endl;
	}
	return 0;
}

//任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，
//本题目要求输出组成指定偶数的两个素数差值最小的素数对。本题含有多组样例输入。

bool isPrime(int n)
{
	int sq = sqrt(n);
	for (int i = 2; i <= sq; ++i)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}

int main()
{
	int num;
	while (cin >> num)
	{
		int half = num / 2;
		int i = 0;
		for (i = half; i > 2; ++i)
		{
			if (isPrime(i) && isPrime(num - i))
				break;
		}

		cout << num - i << endl << i << endl;
	}
	return 0;
}

//给定两个32位整数n和m，同时给定i和j，将m的二进制数位插入到n的二进制的第j到第i位, 
//保证n的第j到第i位均为零，且m的二进制位数小于等于i - j + 1，其中二进制的位数从0开始由低到高。

class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		// write code here
		m <<= j;
		return n | m;
	}
};

//求一个byte数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1

int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0, maxcount = 0;;
		while (n)
		{
			if (n & 1)
			{
				count++;
				maxcount = max(count, maxcount);
			}
			else
				count = 0;

			n >>= 1;
		}

		cout << maxcount << endl;
	}
	return 0;
}

//将一棵无穷大满二叉树的结点按根结点一层一层地从左往右编号，根结点编号为1。
//现给定a，b为两个结点。设计一个算法，返回a、b最近的公共祖先的编号。注意其祖先也可能是结点本身。

class LCA {
public:
	int getLCA(int a, int b) {
		// write code here
		while (a != b)
		{
			if (a > b)
				a /= 2;
			else
				b /= 2;
		}

		return b;
	}
};