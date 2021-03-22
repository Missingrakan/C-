#include <iostream>
#include <vector>

using namespace std;

typedef struct Result
{
	int l;
	int r;
}Result;

Result& search(vector<int>& v, int pos)
{
	Result res = { -1, -1 };

	for (int i = pos - 1; i >= 0; --i)
	{
		if (v[i] < v[pos])
		{
			res.l = i;
			break;
		}
	}

	for (int i = pos + 1; i < v.size(); ++i)
	{
		if (v[i] < v[pos])
		{
			res.r = i;
			break;
		}
	}

	return res;
}

int main()
{
	int n;
	cin >> n;
	vector<int> v;
	v.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	for (int i = 0; i < n; ++i)
	{
		Result res = search(v, i);
		cout << res.l << " " << res.r << endl;
	}

	return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#pragma pack(2)

struct AA {

	int a;       //4-2 2 ---0

	char b;		//1-2 1---4

	short c;    //2-2 2----6

	char d;		//2-1 1----9

};

void main()
{
	cout << sizeof(struct AA) << endl;
}

/*
class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // Ĭ�ϳ�ʼ��0
		for (string str : strs) 
		{ // ������Ʒ
			int oneNum = 0, zeroNum = 0;
			for (char c : str) {
			if (c == '0') zeroNum++;
				else oneNum++;
			}
			for (int i = m; i >= zeroNum; i--) { // �������������ҴӺ���ǰ������
				for (int j = n; j >= oneNum; j--) {
					dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
				}
			}
		}
		return dp[m][n];
	}
};

void main()
{
	vector<string> v = { "10", "0001", "111001", "1", "0"};
	Solution s;
	s.findMaxForm(v, 5, 3);
}
*/

/*
class Solution {
public:
	int minCut(string s) {
		if (s.empty()) return 0;
		int len = s.size();
		vector<int> cut;
		// F(i)��ʼ��
		// F(0��= -1����Ҫ����û����һ������ص��ַ�����aaaaa�����������Ľ��
		for (int i = 0; i < 1 + len; ++i) {
			cut.push_back(i - 1);
		}
		for (int i = 1; i < 1 + len; ++i) 
		{
			for (int j = 0; j < i; ++j) 
			{
				// F(i) = min{F(i), 1 + F(j)}, where j<i && j+1��i�ǻ��Ĵ�
				// ������жϣ�����ӵ�j+1��iΪ�����ַ���
				// ���ټ�һ�ηָ��1��j��j+1��i���ַ���ȫ���ֳ��˻����ַ���
				if (isPalindrome(s, j, i - 1)) {
					cut[i] = min(cut[i], 1 + cut[j]);
				}
			}
		}
		return cut[len];
	}
	//�ж��Ƿ���Ĵ�
	bool isPalindrome(string s, int i, int j){
		while (i<j) {
			if (s[i] != s[j]){
				return false;
			}
			i++;
			j--;
		}
		return true;
	}
};

int main()
{
	string str = "aaaaab";
	Solution s;
	s.minCut(str);
	return 0;
}
*/