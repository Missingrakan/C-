#define _CRT_SECURE_NO_WARNINGS 1


//定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，
//调用 min、push 及 pop 的时间复杂度都是 O(1)。

class MinStack {
public:
	/** initialize your data structure here. */
	stack<int> data, help;
	MinStack() {

	}

	void push(int x) {
		data.push(x);
		// 如果x是data和help的第一个元素，或者x小于等于help的最小元素，入栈
		if (help.empty() || x <= help.top()) help.push(x);
		if (x > help.top())
		{
			// 如果x大于help的最小元素，向help中再压入一遍该最小元素，保持两个栈元素个数相等
			// 比如data里现在有3，help里现在也有3，data里压入一个4，那么help里压入一个3
			// 这样如果把data的4弹出，我们同步把help的3也弹出
			int temp = help.top();
			help.push(temp);
		}
	}

	void pop() {
		if (!data.empty() && !help.empty())
		{
			data.pop();
			help.pop();
		}
	}

	int top() {
		return data.top();
	}

	int min() {
		return help.top();
	}
};

class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		stack<int> help;
		int pushSize = pushed.size(), popSize = popped.size();
		int pos = 0;
		for (int i = 0; i<pushSize; ++i)
		{
			help.push(pushed[i]);
			while (pos < popSize && !help.empty() && help.top() == popped[pos])
			{
				help.pop();
				pos++;
			}
		}
		return help.empty();
	}
};

//从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。

class Solution {
public:
	vector<int> levelOrder(TreeNode* root) {
		if (!root) return{};
		vector<int> res;
		queue<TreeNode *> bfs; // 广度优先搜索（层次遍历）
		bfs.push(root);
		while (!bfs.empty())
		{
			TreeNode *temp = bfs.front();
			res.push_back(bfs.front()->val);
			bfs.pop();
			if (temp->left) bfs.push(temp->left);
			if (temp->right) bfs.push(temp->right);
		}
		return res;
	}
};

//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。



class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) 
	{
		unordered_map<int, int> hashtable;
		for (int i = 0; i < nums.size(); ++i) 
		{
			auto it = hashtable.find(target - nums[i]);
			if (it != hashtable.end()) 
			{
				return{ it->second, i };
			}
			hashtable[nums[i]] = i;
		}
		return{};
	}
};

