#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
//将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
int StrToInt(string str) {
	if (str.empty())
		return 0;
	int symbol = 1;
	if (str[0] == '+')
	{
		symbol = 1;
		str[0] = '0';
	}
	else if (str[0] == '-')
	{
		symbol = -1;
		str[0] = '0';
	}

	int sum = 0;
	int sz = str.size();
	for (int i = 0; i < sz; ++i)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			sum = 0;
			break;
		}

		sum += sum * 10 + str[i] - '0';
	}

	return symbol*sum;
}

int main()
{
	StrToInt("123");
	return 0;
}

/*
//一个数组有 N 个元素，求连续子数组的最大和。 例如：[-1,2,1]，和最大的连续子数组为[2,1]，其和为 3

int main()
{
	int size = 0;
	cin >> size;
	vector<int> num(size);
	for (int i = 0; i < size; ++i)
		cin >> num[i];

	int result = num[0];
	int sum1 = 0, sum2 = 0;

	for (int i = 0; i < size; ++i)
	{
		sum2 = sum1 >= 0 ? sum1 + num[i] : num[i];
		if (sum2 > result)
			result = sum2;
		if (sum2 < 0)
			sum2 = 0;

		sum1 = sum2;
	}

	cout << result << endl;
	return 0;
}
*/

/*
//回文串”是一个正读和反读都一样的字符串，比如“level”或者“noon”等等就是回文串。
//花花非常喜欢这种拥有对称美的回文串，生日的时候她得到两个礼物分别是字符串A和字符串B。
//现在她非常好奇有没有办法将字符串B插入字符串A使产生的字符串是一个回文串。你接受花花的请求，帮助她寻找有多少种插入办法可以使新串是一个回文串。如果字符串B插入的位置不同就考虑为不一样的办法。

bool isCircle(string str)
{
	size_t start = 0;
	size_t end = str.size() - 1;
	while (start <= end)
	{
		if (str[start] != str[end])
			return false;

		start++;
		end--;
	}

	return true;
}

int main()
{
	string str1, str2;
	int count = 0;
	while (cin >> str1 >> str2)
	{
		int sz = str1.size();
		for (size_t i = 0; i <= sz; ++i)
		{
			string tmp = str1;
			tmp.insert(i, str2);
			if (isCircle(tmp))
				count++;
		}
		cout << count << endl;
	}

	return 0;
}
*/


/*
//给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数

int main()
{
	string table = "0123456789ABCDEF", res;
	int m, n;
	cin >> m >> n;

	//标记负数，将负数转换为正数统一处理，最后根据标记输出负数时加上‘-’号
	bool flag = false;
	if (m < 0)
	{
		flag = true;
		m = 0 - m;
	}

	while (m)
	{
		res += table[m%n];
		m /= n;
	}

	if (flag)
		res += '-';

	reverse(res.begin(), res.end());

	cout << res << endl;

	return 0;
}
*/