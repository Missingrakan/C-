#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//题目描述
//1
//1  1  1
//1  2  3  2  1
//1  3  6  7  6  3  1
//1  4  10 16 19  16 10  4  1
//以上三角形的数阵，第一行只有一个数1，以下每行的每个数，是恰好是它上面的数，左上角数到右上角的数，3个数之和（如果不存在某个数，认为该数就是0）。
//求第n行第一个偶数出现的位置。如果没有偶数，则输出 - 1。例如输入3, 则输出2，输入4则输出3。
//输入n(n <= 1000000000)
//本题有多组输入数据，输入到文件末尾，请使用while(cin >> )等方式读入

//输入描述 :
//输入一个int整数
//输出描述 :
//输出返回的int值

int main()
{
	int n, num;
	while (cin >> n)
	{
		//第n行的元素个数
		num = 2 * n - 1;
		vector<vector<int>> vv(n, vector<int>(num, 0));
		//初始化矩阵
		vv[0][0] = 1;
		for (int i = 1; i < n; ++i)
		{
			//第一列和每行的最后一列为 1；
			vv[i][0] = vv[i][i * 2] = 1;
			for (int j = 1; j < 2 * i; ++j)
			{
				if (j == 1)
					//对于第二列进行特殊处理
					vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
				else
					vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1] + vv[i - 1][j - 2];
			}
		}

		int k;
		for (k = 0; k < num; ++k)
		{
			if (vv[n - 1][k] % 2 == 0 && vv[n - 1][k] != 0)
			{
				cout << k + 1 << endl;
				break;
			}
		}

		if (k == num)
		{
			cout << -1 << endl;
		}
	}
	return 0;
}

//题目描述
//扑克牌游戏大家应该都比较熟悉了，一副牌由54张组成，含3~A，2各4张，小王1张，大王1张。牌面从小到大用如下字符和字符串表示（其中，小写joker表示小王，大写JOKER表示大王）:)
//3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
//输入两手牌，两手牌之间用“ - ”连接，每手牌的每张牌以空格分隔，“ - ”两边没有空格，如：4 4 4 4 - joker JOKER
//请比较两手牌大小，输出较大的牌，如果不存在比较关系则输出ERROR
//
//基本规则：
//（1）输入每手牌可能是个子，对子，顺子（连续5张），三个，炸弹（四个）和对王中的一种，不存在其他情况，由输入保证两手牌都是合法的，顺子已经从小到大排列；
//（2）除了炸弹和对王可以和所有牌比较之外，其他类型的牌只能跟相同类型的存在比较关系（如，对子跟对子比较，三个跟三个比较），不考虑拆牌情况（如：将对子拆分成个子）
//（3）大小规则跟大家平时了解的常见规则相同，个子，对子，三个比较牌面大小；顺子比较最小牌大小；炸弹大于前面所有的牌，炸弹之间比较牌面大小；对王是最大的牌；
//（4）输入的两手牌不会出现相等的情况。
//
//答案提示：
//（1）除了炸弹和对王之外，其他必须同类型比较。
//（2）输入已经保证合法性，不用检查输入是否是合法的牌。
//（3）输入的顺子已经经过从小到大排序，因此不用再排序了.
//输入描述:
//输入两手牌，两手牌之间用“ - ”连接，每手牌的每张牌以空格分隔，“ - ”两边没有空格，如4 4 4 4 - joker JOKER。
//输出描述 :
//输出两手牌中较大的那手，不含连接符，扑克牌顺序不变，仍以空格隔开；如果不存在比较关系则输出ERROR。

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string line;
	while (getline(cin, line))
	{
		if (line.find("joker JOKER") != line.npos)
			cout << "joker JOKER" << endl;
		else
		{
			int index = line.find('-');
			//分开手牌
			string str1 = line.substr(0, index);
			string str2 = line.substr(index + 1);

			//统计空格的个数，空格个数+1 = 牌数
			int c1 = count(str1.begin(), str1.end(), ' ');
			int c2 = count(str2.begin(), str2.end(), ' ');

			//取出第一张牌
			string first1 = str1.substr(0, str1.find(' '));
			string first2 = str2.substr(0, str2.find(' '));

			string tmp = "345678910JQKA2jokerJOKER";

			if (c1 == c2)
			{
				//若牌数目相等，且两位玩家手牌不同，故取出第一张牌比较便可
				if (tmp.find(first1) > tmp.find(first2))
					cout << str1 << endl;
				else
					cout << str2 << endl;
			}
			else
			{
				//手牌不同时，说明一方有炸弹，一方是普通牌
				if (c1 == 3)
					cout << str1 << endl;
				else if (c2 == 3)
					cout << str2 << endl;
				else
					cout << "ERROR" << endl;
			}
		}
	}
	return 0;
}

//题目描述
//完全数（Perfect number），又称完美数或完备数，是一些特殊的自然数。
//它所有的真因子（即除了自身以外的约数）的和（即因子函数），恰好等于它本身。
//例如：28，它有约数1、2、4、7、14、28，除去它本身28外，其余5个数相加，1 + 2 + 4 + 7 + 14 = 28。s
//输入n，请输出n以内(含n)完全数的个数。计算范围, 0 < n <= 500000
//本题输入含有多组样例。

//
//输入描述 :
//输入一个数字n
//输出描述 :
//输出不超过n的完全数的个数

int count(int n)
{
	int cot = 0;
	for (int i = 2; i <= n; ++i)
	{
		int sum = 0;
		int sq = sqrt(i);
		for (int j = 2; j <= sq; ++j)
		{
			if (i%j == 0)
			{
				//如果j^2 = i; 只加一次
				if (i / j == j)
					sum += j;
				else
					sum += j + (i / j);
			}
		}
		if (sum + 1 == i)
			cot++;
	}
	return cot;
}

int main()
{
	int num;
	while (cin >> num)
		cout << count(num) << endl;
	return 0;
}


//题目描述
//输入一个正整数，计算它在二进制下的1的个数。注意多组输入输出！！！！！！
//输入描述 :
//输入一个整数
//输出描述 :
//计算整数二进制中1的个数

int main()
{
	int num;
	while (cin >> num)
	{
		int count = 0;
		while (num)
		{
			if (num & 1)
				count++;
			num >>= 1;
		}
		cout << count << endl;
	}
	return 0;
}