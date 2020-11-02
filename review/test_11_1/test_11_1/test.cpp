#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
using namespace std;

void TestVector(size_t n)
{
	vector<vector<int>> vv;

	//开辟每行保存vector元素的空间
	vv.resize(n);

	//开辟每行的空间
	for (size_t i = 0; i < n; ++i)
	{
		vv[i].resize(i + 1, 1);
	}

	//计算杨辉三角除第0列和对角线之外的元素
	for (size_t i = 2; i < n; ++i)
	{
		for (size_t j = 1; j < i; ++j)
			vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
	}

	for (size_t i = 0; i < n; ++i)
	{
		for (size_t j = 0; j < vv[i].size(); ++j)
		{
			printf("%3d",vv[i][j]);
		}

		printf("\n");
	}
}

int main()
{
	TestVector(5);
	return 0;
}

#if 0
int main()
{
	vector<int> v;
	v.push_back(1);
	auto it = v.erase(v.begin());
	if (it == v.end())
		cout << "it == end" << endl;
	else
		cout << "it != end" << endl;
	return 0;
	return 0;
}

#include "Vector.h"
int main()
{
	//TestMyVector1();
	//TestMyVector2();
	TestMyVector3();
	return 0;
}

#endif