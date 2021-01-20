#define _CRT_SECURE_NO_WARNINGS 1

//��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
//��������һ������Ϊ9������{ 1, 2, 3, 2, 2, 2, 5, 4, 2 }��
//��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		std::unordered_map<int, int> match;
		for (const int val : numbers)
			++match[val];

		for (const int val : numbers)
		{
			if (match[val] > numbers.size() / 2)
				return val;
		}
		return 0;
	}
};


/*
class Solution {
public:
int MoreThanHalfNum_Solution(vector<int> numbers) {
		if(numbers.empty())
			return 0;

		sort(numbers.begin(), numbers.end());

		int size = numbers.size();
		int res = numbers[size/2];
		int count = 0;

		for(int i = 0; i < size; ++i)
		{
			if(numbers[i] == res)
				count++;
		}

		return (count > size/2) ? res : 0;
	}
};
*/

/*
//����һ���ַ���str������ַ���str�е�����������ִ�
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;

	string res = "", tmp = "";

	//�˴�ȡ����Ϊ�˱�֤���һ�θ���
	for (int i = 0; i <= str.size(); ++i)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			tmp += str[i];
		}
		else
		{
			if (tmp.size()>res.size())
				res = tmp;
			else
				tmp.clear();
		}
	}

	cout << res << endl;
	return 0;
}
*/

/*
//��һ�仰�ĵ��ʽ��е��ã���㲻���á����� I like beijing. �����������Ϊ��beijing. like I
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string str1, str2;
	cin >> str1;
	while (cin >> str2)
		str1 = str2 + " " + str1;
	cout << str1 << endl;
	return 0;
}


int main()
{
	string str;
	getline(cin, str);

	reverse(str.begin(), str.end());

	auto start = str.begin();
	while (start != str.end())
	{
		auto end = start;
		while ((end != str.end()) && *end != ' ')
			++end;

		reverse(start, end);

		if (end != str.end())
			start = end + 1;
		else
			start = end;
	}

	cout << str << endl;

	return 0;
}
*/

/*
//ţţ��������������Ϊһ��������һ��������������, ��������������Ƿǵ������߷ǵݼ�����ġ�
//ţţ��һ������Ϊn����������A, ��������һ�������ǰ�����A��Ϊ���ɶ�����������, 
//ţţ��֪�������ٿ��԰���������Ϊ��������������.
//��������ʾ, ţţ���԰�����A����Ϊ[1, 2, 3]��[2, 2, 1]��������������, ������Ҫ����Ϊ2������������, �������2

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> v;
	v.resize(n + 1);
	v[n] = 0;
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int i = 0, count = 0;
	while (i < n)
	{
		//�ǵݼ�������
		if (v[i] < v[i + 1])
		{
			while (i < n && v[i] <= v[i + 1])
				i++;
			count++;
			i++;
		}
		else if (v[i] == v[i + 1])
		{
			i++;
		}
		//�ǵ���������
		else
		{
			while (i < n && v[i] >= v[i + 1])
				i++;
			count++;
			i++;
		}
	}

	cout << count << endl;

	return 0;
}
*/