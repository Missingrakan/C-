#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//һ�������� N ��Ԫ�أ�����������������͡� ���磺[-1, 2, 1]������������������Ϊ[2, 1]�����Ϊ 3
//��������:
//����Ϊ���С� ��һ��һ������n(1 <= n <= 100000)����ʾһ����n��Ԫ�� �ڶ���Ϊn��������ÿ��Ԫ��, ÿ����������32λint��Χ�ڡ��Կո�ָ���
//������� :
//���������������к�����ֵ��
//ʾ��1
//����
//3 - 1 2 1
//���
//3
int main()
{
	int size;
	cin >> size;
	vector<int> nums(size);
	for (size_t i = 0; i < size; ++i)
		cin >> nums[i];
	int result = nums[0];
	int sum1 = 0; 
	int sum2 = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		sum2 = sum1 >= 0 ? sum1 + nums[i] : nums[i];
		if (sum2 > result)
			result = sum2;
		if (sum2 < 0)
			sum2 = 0;
		sum1 = sum2;
	}

	cout << result << endl;
	return 0;
}

////�����Ĵ�����һ�������ͷ�����һ�����ַ��������硰level�����ߡ�noon���ȵȾ��ǻ��Ĵ��������ǳ�ϲ������ӵ�жԳ����Ļ��Ĵ������յ�ʱ�����õ���������ֱ����ַ���A���ַ���B���������ǳ�������û�а취���ַ���B�����ַ���Aʹ�������ַ�����һ�����Ĵ�������ܻ��������󣬰�����Ѱ���ж����ֲ���취����ʹ�´���һ�����Ĵ�������ַ���B�����λ�ò�ͬ�Ϳ���Ϊ��һ���İ취��
////���磺
////A = ��aba����B = ��b����������4�ְ�B����A�İ취��
////* ��A�ĵ�һ����ĸ֮ǰ: "baba" ���ǻ���
////* �ڵ�һ����ĸ��a��֮�� : "abba" �ǻ���
////* ����ĸ��b��֮�� : "abba" �ǻ���
////* �ڵڶ�����ĸ'a'֮�� "abab" ���ǻ���
////�������������Ĵ�Ϊ2
////�������� :
////ÿ���������ݹ����С�
////��һ��Ϊ�ַ���A
////�ڶ���Ϊ�ַ���B
////�ַ������Ⱦ�С��100��ֻ����Сд��ĸ
////������� :
////���һ�����֣���ʾ���ַ���B�����ַ���A֮�󹹳�һ�����Ĵ��ķ�����
////ʾ��1
////����
////aba
////b
////���
////2
//bool IsCircle(const string& str)
//{
//	size_t begin = 0;
//	size_t end = str.size() - 1;
//	while (begin < end)
//	{
//		if (str[begin] != str[end])
//			return false;
//		++begin;
//		--end;
//	}
//	return true;
//}
//
//int main()
//{
//	string str1, str2;
//	getline(cin, str1);
//	getline(cin, str2);
//	size_t count = 0;
//	for (size_t i = 0; i <= str1.size(); ++i)
//	{
//		string str = str1;
//		str.insert(i, str2);
//		if (IsCircle(str))
//			++count;
//	}
//	cout << count << endl;
//	return 0;
//}

////����һ��ʮ������M���Լ���Ҫת���Ľ�����N����ʮ������Mת��ΪN������
////�������� :
////����Ϊһ�У�M(32λ����)��N(2 �� N �� 16)���Կո������
////������� :
////Ϊÿ������ʵ�����ת���������ÿ�����ռһ�С����N����9�����Ӧ�����ֹ���ο�16���ƣ����磬10��A��ʾ���ȵȣ�
////ʾ��1
////����
////7 2
////���
////111
//int main()
//{
//	int m, n;
//	cin >> m >> n;
//	string res;
//	string table = "0123456789ABCDEF";
//	bool flag = false;
//	if (m < 0)
//	{
//		m = 0 - m;
//		flag = true;
//	}
//	while (m)
//	{
//		res += table[m%n];
//		m /= n;
//	}
//	if (flag)
//		res += '-';
//	reverse(res.begin(), res.end());
//	cout << res << endl;
//	return 0;
//}

////A, B, C�������Ǻ�����, ÿ�������ﶼ��һЩ�ǹ�, ���ǲ�֪������ÿ�������Ͼ����ж��ٸ��ǹ�, ��������֪�����µ���Ϣ��
////A - B, B - C, A + B, B + C.���ĸ���ֵ.ÿ����ĸ����ÿ������ӵ�е��ǹ���.
////������Ҫͨ�����ĸ���ֵ�����ÿ���������ж��ٸ��ǹ�, ��A, B, C�����ﱣ֤���ֻ��һ������A, B, C������������������
////�������� :
////����Ϊһ�У�һ��4���������ֱ�ΪA - B��B - C��A + B��B + C���ÿո������ ��Χ���� - 30��30֮��(������)��
////������� :
////���Ϊһ�У�����������������A��B��C��˳�����A��B��C���ÿո��������ĩ�޿ո� �������������������A��B��C�������No
////ʾ��1
////����
////1 - 2 3 4
////���
////2 1 3
//int main()
//{
//	int num1, num2, num3, num4;
//	cin >> num1 >> num2 >> num3 >> num4;
//	if ((num2 + num4) / 2 == (num3 - num1) / 2)
//		cout << (num1 + num3) / 2 << " " << (num2 + num4) / 2 << " " << (num4 - num2) / 2 << endl;
//	else
//		cout << "No" << endl;
//	return 0;
//}