#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <functional>

using namespace std;

//����һ���ǿ����飬���ش������� ��������� ����������ڣ��򷵻���������������

int thirdMax(vector<int>& nums) {
	set<int> visited;
	priority_queue<int, vector<int>, greater<int>> topThree;
	for (const auto& num : nums) {
		if (visited.count(num)) {
			continue;
		}
		visited.insert(num);
		topThree.push(num);
		if (topThree.size() > 3) {
			topThree.pop();
		}
	}

	if (topThree.size() == 3) {
		return topThree.top();
	}

	int largest;
	while (!topThree.empty()) {
		largest = topThree.top();
		topThree.pop();
	}

	return largest;
}

void main()
{
	vector<int> v = { 5, 7, 8, 9, 6, 4 };
	int a = thirdMax(v);
}


class Solution3 {
public:
	int thirdMax(vector<int>& nums) {
		set<int> topThree;
		for (const auto& num : nums) {
			topThree.insert(num);
			if (topThree.size() > 3) {
				topThree.erase(topThree.begin());
			}
		}

		assert(!topThree.empty());
		return topThree.size() < 3 ? *topThree.rbegin() : *topThree.begin();
	}
};


//����һ���� ���� ��ɵ� �ǿ� ��������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��
//���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢�������֡�
//����Լ���������� 0 ֮�⣬��������������㿪ͷ��

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int sz = digits.size();
		for (int i = sz - 1; i >= 0; --i)
		{
			digits[i]++;
			//��ǰλ�ӵ�10Ҫ������λ������ѭ��
			if (digits[i] == 10)
				digits[i] = 0;

			//��������λ��ֱ�ӷ���
			else
				return digits;
		}

		//��ѭ����δ���أ�˵����һֱ������λ(999..99+1���)����begin()λ�ò���1����
		digits.insert(digits.begin(), 1);
		return digits;
	}
};

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		//ֻ����ԭ�����в�����
		//������Ӹ�λ���λ��������ǰλֵ��Ϊ9��������ֵΪ0������Ϊ9����ֵ + 1��break�˳�ѭ����
		//����ж�һ�������������99..9 + 1������Ϊ�������������������ѭ������������λ��Ϊ0��ֻ����λ��Ϊ1���ٽ�һ��0ѹ������β�����ɡ�

		int n = digits.size();
		for (int i = n - 1; i >= 0; --i)
		{
			if (digits[i] == 9){
				digits[i] = 0;
			}
			else{
				digits[i] += 1;
				break;
			}
		}
		if (digits[0] == 0){
			digits[0] = 1;
			digits.push_back(0);
		}
		return digits;
	}
};

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v;
		v.resize(n);
		int res;
		for (int i = 0; i < n; ++i)
			cin >> v[i];

		int k;
		cin >> k;

		set<int> s(v.begin(), v.end());

		vector<int> tmp;

		for (const auto& e : s)
			tmp.push_back(e);

		priority_queue<int> que;

		for (int i = 0; i < k; ++i)
			que.push(tmp[i]);

		for (int i = k; i < tmp.size(); ++i)
		{
			if (tmp[i] < que.top())
				que.push(tmp[i]);
		}


		for (int i = 0; i < k; ++i)
		{
			res = que.top();
			que.pop();
		}

		cout << res << endl;
	}
	return 0;
}