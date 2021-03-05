#define _CRT_SECURE_NO_WARNINGS 1

//����һ�����飬�ҳ�������С��K��������������Ԫ����4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4�����K>����ĳ��ȣ���ô����һ���յ�����

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

//��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}��
//��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��

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
			//start �� i �Ĺ�ϵ�ǣ���ʾ��˭��ʼ
			swap(str, start, i);
			//��ȷ�����ĸ��ַ���Ϊ��ʼ����Ҫ�ھ�����һ���ֵ������������
			//����һ��Ҫ�����⣬i�����Ǿ�����˭��Ϊ���еĿ�ʼ��������sub�ַ���ÿ�ο�ʼ����Ҫ��start+1��
			ʼ
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

//����һ�Ŷ������ĸ��ڵ��һ�����������ֵ����ӡ���������н��ֵ�ĺ�Ϊ��������������·����
//·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����

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