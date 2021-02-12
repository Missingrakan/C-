#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>

using namespace std;

//������������ڣ���������һ��ĵڼ��졣��
//
//���������ж��飬ע��ѭ������
//
//�������� :
//������У�ÿ�пո�ָ�ֱ����꣬�£���
//
//������� :
//�ɹ� : ����outDay��������ĵڼ���;
//ʧ��:���� - 1

int main()
{
	int array[12] = { 31, 59, 90, 120, 151, 181, 212,
		243, 273, 304, 334, 365 };
	int year;
	int month;
	int day;

	int sum = 0;

	while (cin >> year >> month >> day)
	{
		sum = 0;
		if (month > 2)
		{
			//�����ȡÿһ�µ�����ʱʹ�������±꿪ʼ�ģ��ʴ���Ӧ��-2
			sum += array[month - 2];
			sum += day;

			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
				sum += 1;
		}
		else
			sum += day;
		cout << sum << endl;
	}
	return 0;
}

//��Ŀ����
//����һ��ż��������2����������2��������ɣ����ż����2�������кܶ������������ĿҪ��������ָ��ż��������������ֵ��С�������ԡ�
//���⺬�ж����������롣
//�������� :
//����һ��ż��
//
//������� :
//�����������


bool IsPrime(int num)
{
	int tmp = sqrt(num);
	for (int i = 2; i <= tmp; ++i)
	{
		if (num%i == 0)
			return false;
	}
	return true;
}

int main()
{
	int num;
	int half;
	int i;
	while (cin >> num)
	{
		half = num / 2;
		//���м俪ʼ�ҷ���������������
		for (i = half; i > 0; --i)
		{
			if (IsPrime(i) && IsPrime(num - i))
				break;
		}
		cout << i << endl << num - i << endl;
	}
	return 0;
}

//����һ�ö������������Լ�վ�������Ҳ࣬���մӶ������ײ���˳�򣬷��ش��Ҳ����ܿ����Ľڵ�ֵ��
//ʾ��:
//���� : [1, 2, 3, null, 5, null, 4]
//��� : [1, 3, 4]


class Solution 
{
public:
	vector<int> rightSideView(TreeNode* root)
	{
		queue<TreeNode*> que;
		if (root != NULL) que.push(root);
		vector<int> result;
		while (!que.empty())
		{
			int size = que.size();
			for (int i = 0; i < size; i++)
			{
				TreeNode* node = que.front();
				que.pop();
				if (i == (size - 1)) result.push_back(node->val); // ��ÿһ������Ԫ�ط���result������
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
			}
		}
		return result;
	}
};

vector<vector<int>> res;
void backtrack(vector<int>& nums, int start, vector<int>& track)
{
	res.push_back(track);
	for (int i = start; i < nums.size(); i++)
	{
		// ��ѡ��
		track.push_back(nums[i]);
		// ����
		backtrack(nums, i + 1, track);
		// ����ѡ��
		track.pop_back();
	}
}

vector<vector<int>> subsets(vector<int>& nums)
{
	// ��¼�߹���·��
	vector<int> track;
	backtrack(nums, 0, track);
	return res;
}

void main()
{
	vector<int> v = { 1, 2, 3 };
	subsets(v);
}
