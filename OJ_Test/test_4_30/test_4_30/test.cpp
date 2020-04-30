#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#include <stack>

using namespace std;

//������A��������B ����С��������ָ �ܱ�A��B��������С��������ֵ�����һ���㷨��������A��B����С��������
//
//�������� :
//��������������A��B��
//
//������� :
//���A��B����С��������
//
//ʾ��1
//����
//5 7
//���
//35
int GetValue(int a, int b)
{
	int res;
	while (res = a%b)
	{
		a = b;
		b = res;
	}
	return b;
}

int main()
{
	int a, b;
	while (cin >> a >> b)
		cout << (a*b) / GetValue(a, b) << endl;
	return 0;
}

////��Ŀ����
////������n���ַ����ַ��������������ַ������ȶ��ǲ�ͬ�ġ��������ѧϰ���������ַ��������򷽷��� 1.�����ַ������ֵ����������磺
////"car" < "carriage" < "cats" < "doggies < "koala"
////2.�����ַ����ĳ����������磺
////"car" < "cats" < "koala" < "doggies" < "carriage"
////������֪���Լ�����Щ�ַ�������˳���Ƿ��������������򷽷�������Ҫæ�ų���Ҷ��������Ҫ������æ��֤��
////�������� :
////�����һ��Ϊ�ַ�������n(n �� 100)
////��������n��, ÿ��һ���ַ���, �ַ������Ⱦ�С��100������Сд��ĸ���
////������� :
////�����Щ�ַ����Ǹ����ֵ������ж����Ǹ��ݳ����������"lexicographically",
////
////������ݳ������ж������ֵ����������"lengths",
////
////������ַ�ʽ���������"both"���������"none"
////ʾ��1
////����
////3
////a
////aa
////bbb
////���
////both
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<string> v;
//	v.resize(n);
//	for (auto &ele : v)
//		cin >> ele;
//	bool lensystem = true, lexsystem = true;
//	for (size_t i = 1; i < v.size(); ++i)
//	{
//		if (v[i - 1].size() >= v[i].size())
//		{
//			lensystem = false;
//			break;
//		}
//	}
//
//	for (size_t i = 1; i < v.size(); ++i)
//	{
//		if (v[i - 1] >= v[i])
//		{
//			lexsystem = false;
//			break;
//		}
//	}
//
//	if (lensystem && lexsystem)
//		cout << "both" << endl;
//	else if (!lensystem && lexsystem)
//		cout << "lexicographically" << endl;
//	else if (lensystem && !lexsystem)
//		cout << "lengths" << endl;
//	else
//		cout << "none" << endl;
//	//    if(lensystem && lexsystem)
//	//        cout << "both" << endl;
//	//    else if(lensystem == false && lexsystem == true)
//	//        cout << "lexicographically" << endl;
//	//    else if(lensystem == true && lexsystem == false)
//	//        cout << "lengths" << endl;
//	//    else
//	//        cout << "none" << endl;
//	return 0;
//}

////����һ���ַ����������һ���㷨���ж����Ƿ�Ϊһ���Ϸ������Ŵ���
////
////����һ���ַ���A�����ĳ���n���뷵��һ��boolֵ�������Ƿ�Ϊһ���Ϸ������Ŵ���
////
////����������
////"(()())", 6
////���أ�true
////����������
////"()a()()", 7
////���أ�false
////����������
////"()(()()", 7
////���أ�false
//bool chkParenthesis(string A, int n)
//{
//	stack<char> s;
//	for (auto ele : A)
//	{
//		switch (ele)
//		{
//		case '(':
//			s.push(ele);
//			break;
//		case ')':
//		{
//			if (s.empty() || s.top() != '(')
//				return false;
//			else
//				s.pop();
//		}
//			break;
//		default:
//			return false;
//		}
//	}
//	return true;
//}
//
//int main()
//{
//	string s = "(((())))";
//	cout << chkParenthesis(s, s.size()) << endl;
//	return 0;
//}

////Fibonacci��������������ģ�
////F[0] = 0
////F[1] = 1
////for each i �� 2: F[i] = F[i - 1] + F[i - 2]
////��ˣ�Fibonacci���о����磺0, 1, 1, 2, 3, 5, 8, 13, ...����Fibonacci�����е������ǳ�ΪFibonacci��������һ��N�����������Ϊһ��Fibonacci����ÿһ������԰ѵ�ǰ����X��ΪX - 1����X + 1�����ڸ���һ����N��������Ҫ���ٲ����Ա�ΪFibonacci����
////�������� :
////����Ϊһ��������N(1 �� N �� 1, 000, 000)
////������� :
////���һ����С�Ĳ�����ΪFibonacci��"
////ʾ��1
////����
////15
////���
////2
//int main()
//{
//	int f = 0, f0 = 0, f1 = 1;
//	int N = 0;
//	cin >> N;
//	int left = 0,right = 0;
//	while (1)
//	{
//		f = f0 + f1;
//		f0 = f1;
//		f1 = f;
//		if (f < N)
//			left = N - f;
//		else
//		{
//			right = f - N;
//			break;
//		}
//	}
//	cout << min(left, right) << endl;
//	return 0;
//}