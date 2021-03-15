#define _CRT_SECURE_NO_WARNINGS 1

#include <vector>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

//����һ���ɷǸ���������m x n�Ķ�ά���飬����Ҫ�Ӷ�ά��������Ͻ��ߵ����½ǣ����ҳ�·���ϵ���������֮����С��·����
//ע�⣺��ÿ��ֻ�����»������ƶ���

class Solution {
public:
	/**
	*
	* @param grid int����vector<vector<>>
	* @return int����
	*/
	int minPathSum(vector<vector<int> >& grid) {
		// write code here

		if (grid.empty())
			return 0;

		int row = grid.size();
		int col = grid[0].size();

		vector<vector<int>> dp(row, vector<int>(col, 0));

		//��ʼ����0�е�0��
		dp[0][0] = grid[0][0];
		for (int i = 1; i < row; ++i)
		{
			dp[i][0] = grid[i][0] + dp[i - 1][0];
		}

		for (int j = 1; j < col; ++j)
		{
			dp[0][j] = grid[0][j] + dp[0][j - 1];
		}

		for (int i = 1; i < row; ++i)
		{
			for (int j = 1; j < col; ++j)
			{
				dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
			}
		}

		return dp[row - 1][col - 1];
	}
};

//һ����������m��n��С�ĵ�ͼ�����Ͻǣ���㣩��
//������ÿ�����»������ƶ���������Ҫ�����ͼ�����½ǣ��յ㣩��
//�����ж����ֲ�ͬ��·��������ߵ��յ㣿

class Solution {
public:
	/**
	*
	* @param m int����
	* @param n int����
	* @return int����
	*/
	int uniquePaths(int m, int n) {
		// write code here
		if (m < 1 || n < 1)
			return 0;

		vector<vector<int>> dp(m, vector<int>(n, 1));

		//(0,0)Ϊ������λ��
		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}

		return dp[m - 1][n - 1];
	}
};

void main()
{
	Solution s;
	s.uniquePaths(3, 4);
}

/*

//����һ�������Σ�����������ζ������ײ�����С·���ͣ�ÿһ���������ƶ�������һ�����ڵ����֣�
//���磬���������������£�
//[[20],[30,40],[60,50,70],[40,10,80,30]]
//��С�ĴӶ������ײ���·������20 + 30 + 50 + 10 = 110��

class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		if (triangle.empty())
			return 0;

		vector<vector<int>> dp(triangle);
		int line = triangle.size();

		for (int i = line - 2; i >= 0; --i)
		{
			for (int j = 0; j <= i; ++j)
			{
				dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
			}
		}

		return dp[0][0];
	}

	int minimumTotal(vector<vector<int>> &triangle) {
		if (triangle.empty()){
			return 0;
		}
		// F[i][j], F[0][0]��ʼ��
		vector<vector<int>> min_sum(triangle);
		int line = triangle.size();
		for (int i = 1; i < line; i++){
			for (int j = 0; j <= i; j++){
				// ������߽���ұ߽�
				if (j == 0){
					min_sum[i][j] = min_sum[i - 1][j];
				}
				else if (j == i){
					min_sum[i][j] = min_sum[i - 1][j - 1];
				}
				else{
					min_sum[i][j] = min(min_sum[i - 1][j], min_sum[i - 1][j - 1]);
				}
				// F(i,j) = min( F(i-1, j-1), F(i-1, j)) + triangle[i][j]
				min_sum[i][j] = min_sum[i][j] + triangle[i][j];
			}
		}
		int result = min_sum[line - 1][0];
		// min(F(n-1, i))
		for (int i = 1; i < line; i++){
			result = min(min_sum[line - 1][i], result);
		}
		return result;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> vv = { { 20 }, { 30, 40 }, { 60, 50, 70 }, { 40, 10, 80, 30 } };
	s.minimumTotal(vv);
	return 0;
}
*/

/*

//����һ���ַ���s��һ�鵥��dict���ж�s�Ƿ�����ÿո�ָ��һ���������У�ʹ�õ������������еĵ��ʶ���dict�еĵ��ʣ����п��԰���һ���������ʣ���
//����:
//����s = ��nowcode����
//dict = ["now", "code"].

class Solution{
public:
	bool wordBreak(string s, unordered_set<string> &dict){
		if (s.empty()){
			return false;
		}
		if (dict.empty()){
			return false;
		}
		vector<bool> can_break(s.size() + 1, false);
		// ��ʼ��F(0) = true
		can_break[0] = true;
		for (int i = 1; i <= s.size(); i++){
			for (int j = i - 1; j >= 0; j--){
				// F(i): true{j <i && F(j) && substr[j+1,i]���ڴʵ����ҵ�} OR false
				// ��j+1���ַ�������Ϊj
				if (can_break[j] && dict.find(s.substr(j, i - j)) != dict.end()){
					can_break[i] = true;
					break;
				}
			}
		}
		return can_break[s.size()];
	}
};

int main()
{
	Solution s;
	string str = "leetcode";
	unordered_set<string> set = { "leet", "code" };
	s.wordBreak(str, set);
	return 0;
}
*/