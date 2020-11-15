#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

//根据输入的日期，计算是这一年的第几天。。
//
//测试用例有多组，注意循环输入
//
//输入描述 :
//输入多行，每行空格分割，分别是年，月，日
//
//输出描述 :
//成功 : 返回outDay输出计算后的第几天;
//失败:返回 - 1

int main()
{
	int array[12] = { 31, 59, 90, 120, 151, 181, 212,
		243, 273, 304, 334, 365 };
	int year;
	int month;
	int day;

	int sum = 0;

	while (cin >> year >> month >> day)
	{
		sum = 0;
		if (month > 2)
		{
			//这里获取每一月的天数时使用数组下标开始的，故此数应是-2
			sum += array[month - 2];
			sum += day;

			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
				sum += 1;
		}
		else
			sum += day;
		cout << sum << endl;
	}
	return 0;
}

//题目描述
//在命令行输入如下命令：
//xcopy / s c : \ d : \，
//各个参数如下：
//参数1：命令字xcopy
//参数2：字符串 / s
//参数3：字符串c : \
//参数4 : 字符串d : \
//请编写一个参数解析程序，实现将命令行各个参数解析出来。
//解析规则：
//
//1.参数分隔符为空格
//2.对于用“”包含起来的参数，如果中间有空格，不能解析为多个参数。比如在命令行输入xcopy / s “C : \program files” “d : \”时，参数仍然是4个，第3个参数应该是字符串C : \program files，而不是C : \program，注意输出参数时，需要将“”去掉，引号不存在嵌套情况。
//3.参数不定长
//4.输入由用例保证，不会出现不符合要求的输入
//
//输入描述 :
//输入一行字符串，可以有空格
//
//输出描述 :
//输出参数个数，分解后的参数，每个参数都独占一行

int main()
{
	string str;
	while (getline(cin, str))
	{
		//先统计输出参数的个数
		int count = 0;
		int size = str.size();
		for (int i = 0; i < size; ++i)
		{
			if (str[i] == ' ')
				count++;
			//对‘”’进行特殊处理
			if (str[i] == '"')
			{
				do{
					i++;
				} while (str[i] != '"');
			}
		}

		cout << count + 1 << endl;

		//用flag表示是否含双引号，0表示有双引号
		//注意：双引号中的空格要打印出来
		//这里采用异或来操作flag的值， 两个双引号可以使其复原
		int flag = 1;
		for (int i = 0; i < size; ++i)
		{
			//有双引号，flag通过异或变为0，下一次再遇到双引号flag变为1
			if (str[i] == '"')
				flag ^= 1;
			//打印有效元素
			if (str[i] != ' ' && str[i] != '"')
				cout << str[i];
			//打印双引号内的空格，是否有双引号已用flag标记
			if (str[i] == ' ' && (!flag))
				cout << str[i];
			//遇到双引号外面的就换行
			if (str[i] == ' ' && flag)
				cout << endl;
		}
		cout << endl;
	}
	return 0;
}

//题目描述
//任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，本题目要求输出组成指定偶数的两个素数差值最小的素数对。
//本题含有多组样例输入。
//输入描述 :
//输入一个偶数
//
//输出描述 :
//输出两个素数


bool IsPrime(int num)
{
	int tmp = sqrt(num);
	for (int i = 2; i <= tmp; ++i)
	{
		if (num%i == 0)
			return false;
	}
	return true;
}

int main()
{
	int num;
	int half;
	int i;
	while (cin >> num)
	{
		half = num / 2;
		//从中间开始找符合条件的素数；
		for (i = half; i > 0; --i)
		{
			if (IsPrime(i) && IsPrime(num - i))
				break;
		}
		cout << i << endl << num - i << endl;
	}
	return 0;
}