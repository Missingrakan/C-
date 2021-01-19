#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

/*
//���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ������磬
//���롱They are students.���͡�aeiou������ɾ��֮��ĵ�һ���ַ�����ɡ�Thy r stdnts.��

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);

	int hashtable[256] = { 0 };
	for (const auto&e : str2)
		hashtable[e]++;

	string tmp;
	for (const auto&e : str1)
	{
		if (hashtable[e] == 0)
			tmp += e;
	}

	cout << tmp << endl;

	return 0;
}
*/

/*
//ţţ�ٰ���һ�α�̱���, �μӱ�������3*n��ѡ��, ÿ��ѡ�ֶ���һ��ˮƽֵa_i.
//����Ҫ����Щѡ�ֽ������, һ�����n������, ��ÿ������3��.ţţ���ֶ����ˮƽֵ���ڸö����Ա�еڶ���ˮƽֵ��

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		long long sum = 0;
		vector<int> v;
		v.resize(3 * n);
		for (int i = 0; i < 3 * n; ++i)
			cin >> v[i];

		sort(v.begin(), v.end());

		for (int i = n; i <= 3 * n - 2; i += 2)
			sum += v[i];

		cout << sum << endl;
	}
	return 0;
}
*/

/*
//����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У�������
//���ᱻ��˳������λ��, ����Լ������������ظ�Ԫ��
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		//���ֲ���
		int sz = nums.size();
		int left = 0;
		int right = sz - 1;
		int mid, pos = sz;
		while (left <= right)
		{
			mid = left + (right - left) / 2;
			if (nums[mid] >= target)
			{
				pos = mid;
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}

		return pos;
	}
};
*/

/*
//����һ������ nums ��һ��ֵ val������Ҫ ԭ�� �Ƴ�������ֵ���� val ��Ԫ�أ��������Ƴ���������³��ȡ�
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int size = nums.size();
		for (int i = 0; i < size; i++) {
			if (nums[i] == val) { // ������Ҫ�Ƴ���Ԫ�أ��ͽ����鼯����ǰ�ƶ�һλ
				for (int j = i + 1; j < size; j++) {
					nums[j - 1] = nums[j];
				}
				i--; // ��Ϊ�±�i�Ժ����ֵ����ǰ�ƶ���һλ������iҲ��ǰ�ƶ�һλ
				size--; // ��ʱ����Ĵ�С-1
			}
		}
		return size;

	}
};

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.empty()) return 0;
		int n = nums.size();

		int cur = 0;
		for (int i = 0; i < n; i++) {
			//�Ҳ���ɾ��Ԫ�ص�ֵ�����cur��
			if (nums[i] != val) {
				nums[cur] = nums[i];
				cur++;
			}
		}
		return cur;
	}
};
*/

/*
int main()
{
	int a;
	a = 'A' + 1.6;
	//cout << typeid(a).name() << endl;
	cout << a << endl;
	return 0;
}
*/