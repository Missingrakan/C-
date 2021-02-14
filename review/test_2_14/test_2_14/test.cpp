#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>

using namespace std;

#include<iostream>
using namespace std;

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		//以最短的字符串作为s1
		if (str1.size() > str2.size())
			swap(str1, str2);
		int len1 = str1.size(), len2 = str2.size();
		int i, j, start = 0, max = 0;
		vector<vector<int>> MCS(len1 + 1, vector<int>(len2 + 1, 0));
		for (i = 1; i <= len1; i++)
		for (j = 1; j <= len2; j++)
		{
			if (str1[i - 1] == str2[j - 1])
				MCS[i][j] = MCS[i - 1][j - 1] + 1;
			//如果有更长的公共子串，更新长度
			if (MCS[i][j] > max)
			{
				max = MCS[i][j];
				//以i结尾的最大长度为max, 则子串的起始位置为i - max
				start = i - max;
			}
		}
		cout << str1.substr(start, max) << endl;
	}
	return 0;
}

//三个空汽水瓶可以换一瓶汽水

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

int calculateNum(int n)
{
	int sum = 0;

	//空瓶大于等于2就能换
	while (n >= 2)
	{
		//现在就能喝的
		int res = n / 3;
		//不够的剩余的瓶子
		int remainder = n % 3;
		sum += res;

		//下次可用空瓶
		n = res + remainder;

		if (n == 2)
		{
			++sum;
			break;
		}
	}

	return sum;
}

int main()
{
	int num = 0;
	while (cin >> num)
	{
		if (num == 0)
			continue;
		cout << calculateNum(num) << endl;
	}
	return 0;
}

//*：匹配0个或以上的字符（字符由英文字母和数字0-9组成，不区分大小写。下同）
//？：匹配1个字符

//输入
//te ? t*.*
//txt12.xls
//输出
//false


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
		bool ret = match(model.c_str(), str.c_str());
		if (ret)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}


//有一只兔子，从出生后第3个月起每个月都生一只兔子，
//小兔子长到第三个月后每个月又生一只兔子，假如兔子都不死，问每个月的兔子总数为多少？

int main()
{
	int month = 0;
	while (cin >> month)
	{
		if (month == 1 || month == 2)
		{
			cout << 1 << endl;
			continue;
		}
		int first = 1;
		int second = 1;
		int res = 0;
		for (int i = 3; i <= month; ++i)
		{
			res = first + second;
			first = second;
			second = res;
		}

		cout << res << endl;
	}
	return 0;
}