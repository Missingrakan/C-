#define _CRT_SECURE_NO_WARNINGS 1

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

//题目描述
//有这样一道智力题：“某商店规定：三个空汽水瓶可以换一瓶汽水。小张手上有十个空汽水瓶，她最多可以换多少瓶汽水喝？”答案是5瓶，方法如下：先用9个空瓶子换3瓶汽水，喝掉3瓶满的，喝完以后4个空瓶子，用3个再换一瓶，喝掉这瓶满的，这时候剩2个空瓶子。然后你让老板先借给你一瓶汽水，喝掉这瓶满的，喝完以后用3个空瓶子换一瓶满的还给老板。如果小张手上有n个空汽水瓶，最多可以换多少瓶汽水喝？
//输入描述 :
//输入文件最多包含10组测试数据，每个数据占一行，仅包含一个正整数n（1 <= n <= 100），表示小张手上的空汽水瓶数。n = 0表示输入结束，你的程序不应当处理这一行。
//
//输出描述 :
//对于每组测试数据，输出一行，表示最多可以喝的汽水瓶数。如果一瓶也喝不到，输出0。

/*
int main()
{
	int number;
	while (cin >> number && number != 0)
	{
		cout << number/2 << endl;
	}
	return 0;
}
*/

int calculateNum(int num)
{
	//总兑换数
	int sum = 0;
	while (num > 1)
	{
		//每三瓶换一瓶
		int result = num / 3;
		//剩余不足三瓶的先保留
		int reminder = num % 3;
		sum = sum + result;
		//下一次可以兑换的空瓶
		num = result + reminder;

		//向老板借瓶子
		if (num == 2)
		{
			++sum;
			break;
		}
	}
	return sum;
}

int main()
{
	int number;
	while (cin >> number && number != 0)
	{
		cout << calculateNum(number) << endl;
	}
	return 0;
}


//题目描述
//问题描述：在计算机中，通配符一种特殊语法，广泛应用于文件搜索、数据库、正则表达式等领域。现要求各位实现字符串通配符的算法。
//要求：
//实现如下2个通配符：
//*：匹配0个或以上的字符（字符由英文字母和数字0 - 9组成，不区分大小写。下同）
//？：匹配1个字符
//
//输入：
//通配符表达式；
//一组字符串。
//输出：
//返回匹配的结果，正确输出true，错误输出false
//
//输入描述 :
//先输入一个带有通配符的字符串，再输入一个需要匹配的字符串
//输出描述 :
//返回匹配的结果，正确输出true，错误输出false

bool match(const char* model, const char* str)
{
	if (*model == '\0' && *str == '\0')
		return true;
	//两个字符有一个先结束则返回false
	if (*model == '\0' || *str == '\0')
		return false;

	if (*model == '?')
		//遇到？时，匹配一个字符
		return match(model + 1, str + 1);
	else if (*model == '*')
		//遇到*时，可能匹配0个(str不挪动)，1个(两者都向前挪动)或多个(str后移)
		return match(model + 1, str) || match(model + 1, str + 1) || match(model, str + 1);
	else if (*model == *str)
		return match(model + 1, str + 1);

	return false;
}

int main()
{
	string model, str;
	while (cin >> model >> str)
	{
		int ret = match(model.c_str(), str.c_str());
		if (ret)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}

//题目描述
//请设计一个算法完成两个超长正整数的加法。
//输入描述 :
//输入两个字符串数字
//
//输出描述 :
//输出相加后的结果，string型

string addStrings(string num1, string num2) {
	//由低位向高位相加
	int i = num1.size() - 1;
	int j = num2.size() - 1;
	string result = "";
	//当前位的相加结果
	int carry = 0;
	while (i >= 0 || j >= 0) 
	{
		if (i >= 0) {
			carry += num1[i] - '0';
		}
		if (j >= 0) {
			carry += num2[j] - '0';
		}
		//当前的最大值不大于10
		result += (char)(carry % 10 + '0');
		//如果大于10,向上进一位
		carry /= 10;
		i--;
		j--;
	}
	//相加完之后，如果还有进位，则再加1
	if (carry == 1) {
		result += '1';
	}
	//整体逆置
	reverse(result.begin(), result.end());
	return result;
}
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		cout << addStrings(s1, s2) << endl;
	}
	return 0;
}