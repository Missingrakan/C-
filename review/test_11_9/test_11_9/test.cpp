#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#include <iostream>
#include <string>

using namespace std;

//��Ŀ����
//�����Ĵ�����һ�������ͷ�����һ�����ַ��������硰level�����ߡ�noon���ȵȾ��ǻ��Ĵ���
//�����ǳ�ϲ������ӵ�жԳ����Ļ��Ĵ������յ�ʱ�����õ���������ֱ����ַ���A���ַ���B��
//�������ǳ�������û�а취���ַ���B�����ַ���Aʹ�������ַ�����һ�����Ĵ���
//����ܻ��������󣬰�����Ѱ���ж����ֲ���취����ʹ�´���һ�����Ĵ�������ַ���B�����λ�ò�ͬ�Ϳ���Ϊ��һ���İ취��
//���磺
//A = ��aba����B = ��b����������4�ְ�B����A�İ취��
//* ��A�ĵ�һ����ĸ֮ǰ: "baba" ���ǻ���
//* �ڵ�һ����ĸ��a��֮�� : "abba" �ǻ���
//* ����ĸ��b��֮�� : "abba" �ǻ���
//* �ڵڶ�����ĸ'a'֮�� "abab" ���ǻ���
//�������������Ĵ�Ϊ2
//�������� :
//ÿ���������ݹ����С�
//��һ��Ϊ�ַ���A
//�ڶ���Ϊ�ַ���B
//�ַ������Ⱦ�С��100��ֻ����Сд��ĸ
//������� :
//���һ�����֣���ʾ���ַ���B�����ַ���A֮�󹹳�һ�����Ĵ��ķ�����

bool IsCircle(const string& s)
{
	size_t begin = 0;
	size_t end = s.size() - 1;

	while (begin < end)
	{
		if (s[begin] != s[end])
			return false;

		++begin;
		--end;
	}

	return true;
}

int main()
{
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	int count = 0;

	for (size_t i = 0; i <= str1.size(); ++i)
	{
		string str = str1;
		str.insert(i, str2);
		if (IsCircle(str))
			count++;
	}

	cout << count << endl;
	return 0;
}


//����һ��ʮ������M���Լ���Ҫת���Ľ�����N����ʮ������Mת��ΪN������
//�������� :
//����Ϊһ�У�M(32λ����)��N(2 �� N �� 16)���Կո������
//������� :
//Ϊÿ������ʵ�����ת���������ÿ�����ռһ�С����N����9�����Ӧ�����ֹ���ο�16���ƣ����磬10��A��ʾ���ȵȣ�

int main()
{
	string s, table = "0123456789ABCDEF";
	int m, n;
	cin >> m >> n;
	bool flag = false;

	//���������һ��
	if (m < 0)
	{
		m = 0 - m;
		flag = true;
	}

	while (m)
	{
		s += table[m%n];
		m /= n;
	}

	if (flag)
		s += '-';

	reverse(s.begin(), s.end());
	cout << s << endl;

	return 0;
}

//����һ���ַ���str������ַ���str�е�����������ִ�
//�������� :
//�������������1������������һ���ַ���str�����Ȳ�����255��
//������� :
//��һ�������str��������������ִ���

int main()
{
	string str, cur = "", res = "";
	cin >> str;
	for (int i = 0; i <= str.size(); ++i)
	{
		if (str[i] >= '0' && str[i] <= '9')
			cur += str[i];
		else
		{
			if (cur.size() > res.size())
				res = cur;
			else
				cur = "";
		}
	}

	cout << res;

	return 0;
}

//��һ�仰�ĵ��ʽ��е��ã���㲻���á����� I like beijing.�����������Ϊ��beijing.like I
//�������� :
//ÿ�������������1������������ I like beijing.�����������Ȳ�����100
//������� :
//�����������֮����ַ���, �Կո�ָ�

int main()
{
	string s;
	getline(cin, s);

	reverse(s.begin(), s.end());

	auto start = s.begin();
	while (start != s.end())
	{
		auto end = start;
		while (end != s.end() && *end != ' ')
			end++;

		reverse(start, end);

		if (end != s.end())
			start = end + 1;
		else
			start = end;
	}

	cout << s << endl;
	return 0;
}

int main()
{
	string s1, s2;
	cin >> s1;

	while (cin >> s2)
		s2 = s2 + " " + s1;

	cout << s2;
	return 0;
}