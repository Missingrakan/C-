#define _CRT_SECURE_NO_WARNINGS 1

//给定一个数组，找出其中最小的K个数。例如数组元素是4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。如果K>数组的长度，那么返回一个空的数组

class Solution {
public:
	struct cmp
	{
		bool operator()(const int& a, const int& b)
		{
			return a < b;
		}
	};
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> res;

		if (input.size() == 0 || k <= 0 || k > input.size())
			return res;

		priority_queue<int, vector<int>, cmp> q;
		for (int i = 0; i < input.size(); ++i)
		{
			if (i < k)
				q.push(input[i]);
			else
			{
				if (input[i] < q.top())
				{
					q.pop();
					q.push(input[i]);
				}
			}
		}

		for (int i = 0; i < k; ++i)
		{
			res.push_back(q.top());
			q.pop();
		}

		return res;
	}
};

//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
//由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		std::unordered_map<int, int> match;
		for (const int val : numbers)
			++match[val];

		for (const int val : numbers)
		{
			if (match[val] > numbers.size() / 2)
				return val;
		}
		return 0;
	}
};

class Solution {
public:
	void swap(string &str, int i, int j){
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
	bool IsExist(vector<string>& result, string &str){
		auto it = result.begin();
		for (; it != result.end(); ++it){
			if (*it == str){
				return true;
			}
		}
		return false;
	}
	void PermutationHelper(string &str, int start, vector<string>& result){
		if (start == str.length() - 1){
			if (!IsExist(result, str)){
				result.push_back(str);
			}
			return;
		}
		for (int i = start; i < (int)str.size(); i++){
			//start 和 i 的关系是：表示以谁开始
			swap(str, start, i);
			//当确定以哪个字符作为开始，就要在决定另一部分的排列组合种类
			//这里一定要深刻理解，i仅仅是决定以谁作为排列的开始，但是求sub字符串每次开始，都要从start+1开
			始
				PermutationHelper(str, start + 1, result);
			swap(str, start, i);
		}
	}
	vector<string> Permutation(string str) {
		vector<string> result;
		if (str.length() > 0){
			PermutationHelper(str, 0, result);
			sort(result.begin(), result.end());
		}
		return result;
	}
};

//输入一颗二叉树的根节点和一个整数，按字典序打印出二叉树中结点值的和为输入整数的所有路径。
//路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
class Solution {
public:
	void FindPathDFS(TreeNode* root, int expectNumber, vector<vector<int>>& res, vector<int>& list)
	{
		if (root == NULL)
			return;

		list.push_back(root->val);
		expectNumber -= root->val;

		if (root->left == nullptr && root->right == nullptr && expectNumber == 0)
			res.push_back(list);

		FindPathDFS(root->left, expectNumber, res, list);
		FindPathDFS(root->right, expectNumber, res, list);

		list.pop_back();
	}

	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		vector<vector<int>> res;
		vector<int> list;

		FindPathDFS(root, expectNumber, res, list);
		return res;
	}
};