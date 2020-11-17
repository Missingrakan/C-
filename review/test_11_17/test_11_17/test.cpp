#define _CRT_SECURE_NO_WARNINGS 1

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

//��Ŀ����
//������һ�������⣺��ĳ�̵�涨����������ˮƿ���Ի�һƿ��ˮ��С��������ʮ������ˮƿ���������Ի�����ƿ��ˮ�ȣ�������5ƿ���������£�����9����ƿ�ӻ�3ƿ��ˮ���ȵ�3ƿ���ģ������Ժ�4����ƿ�ӣ���3���ٻ�һƿ���ȵ���ƿ���ģ���ʱ��ʣ2����ƿ�ӡ�Ȼ�������ϰ��Ƚ����һƿ��ˮ���ȵ���ƿ���ģ������Ժ���3����ƿ�ӻ�һƿ���Ļ����ϰ塣���С��������n������ˮƿ�������Ի�����ƿ��ˮ�ȣ�
//�������� :
//�����ļ�������10��������ݣ�ÿ������ռһ�У�������һ��������n��1 <= n <= 100������ʾС�����ϵĿ���ˮƿ����n = 0��ʾ�����������ĳ���Ӧ��������һ�С�
//
//������� :
//����ÿ��������ݣ����һ�У���ʾ�����Ժȵ���ˮƿ�������һƿҲ�Ȳ��������0��

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
	//�ܶһ���
	int sum = 0;
	while (num > 1)
	{
		//ÿ��ƿ��һƿ
		int result = num / 3;
		//ʣ�಻����ƿ���ȱ���
		int reminder = num % 3;
		sum = sum + result;
		//��һ�ο��Զһ��Ŀ�ƿ
		num = result + reminder;

		//���ϰ��ƿ��
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


//��Ŀ����
//�����������ڼ�����У�ͨ���һ�������﷨���㷺Ӧ�����ļ����������ݿ⡢������ʽ��������Ҫ���λʵ���ַ���ͨ������㷨��
//Ҫ��
//ʵ������2��ͨ�����
//*��ƥ��0�������ϵ��ַ����ַ���Ӣ����ĸ������0 - 9��ɣ������ִ�Сд����ͬ��
//����ƥ��1���ַ�
//
//���룺
//ͨ������ʽ��
//һ���ַ�����
//�����
//����ƥ��Ľ������ȷ���true���������false
//
//�������� :
//������һ������ͨ������ַ�����������һ����Ҫƥ����ַ���
//������� :
//����ƥ��Ľ������ȷ���true���������false

bool match(const char* model, const char* str)
{
	if (*model == '\0' && *str == '\0')
		return true;
	//�����ַ���һ���Ƚ����򷵻�false
	if (*model == '\0' || *str == '\0')
		return false;

	if (*model == '?')
		//������ʱ��ƥ��һ���ַ�
		return match(model + 1, str + 1);
	else if (*model == '*')
		//����*ʱ������ƥ��0��(str��Ų��)��1��(���߶���ǰŲ��)����(str����)
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

//��Ŀ����
//�����һ���㷨������������������ļӷ���
//�������� :
//���������ַ�������
//
//������� :
//�����Ӻ�Ľ����string��

string addStrings(string num1, string num2) {
	//�ɵ�λ���λ���
	int i = num1.size() - 1;
	int j = num2.size() - 1;
	string result = "";
	//��ǰλ����ӽ��
	int carry = 0;
	while (i >= 0 || j >= 0) 
	{
		if (i >= 0) {
			carry += num1[i] - '0';
		}
		if (j >= 0) {
			carry += num2[j] - '0';
		}
		//��ǰ�����ֵ������10
		result += (char)(carry % 10 + '0');
		//�������10,���Ͻ�һλ
		carry /= 10;
		i--;
		j--;
	}
	//�����֮��������н�λ�����ټ�1
	if (carry == 1) {
		result += '1';
	}
	//��������
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