#define _CRT_SECURE_NO_WARNINGS 1

//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//你可以假设数组是非空的，并且给定的数组总是存在多数元素。
//示例 1 :
//
//输入 : [1, 2, 3, 2, 2, 2, 5, 4, 2]
//输出 : 2

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		unordered_map<int, int> match;
		int len = nums.size(), res = 10086;
		if (len == 1 || len == 2){
			return nums[0];
		}

		for (int i = 0; i < len; ++i){
			match[nums[i]] ++;
			if (match[nums[i]] >(len / 2)){
				res = nums[i];
				break;
			}
		}
		return res;
	}
};

//方法二：摩尔投票法（本题最佳解法）。其实就是诸侯乱战，你作为东方大国，拥有超过总数 1 / 2 的兵力，
//且规定一个兵打一个兵必定同归于尽，那么即使全部诸侯打你一个，最后剩下的兵肯定也是你的兵，也就是你赢了。
//所以我们的策略就是，先让 res = nums[0]，mole_vote = 1，然后往后迭代。
//但凡遇到下一个不等于 res，就让 mole_vote --（相当于和一个敌人同归于尽）；
//如果下一个等于 res，则mole_vote ++。如果 mole_vote == 0 了，就让 res 等于当前 numes[i]。


class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int moleVote = 0, res = 0;
		for (int i : nums){
			if (moleVote == 0){
				res = i;
			}
			moleVote += res == i ? 1 : -1;
		}
		return res;
	}
};

//输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

//示例 1：
//输入：arr = [3, 2, 1], k = 2
//输出：[1, 2] 或者[2, 1]

//示例 2：
//输入：arr = [0, 1, 2, 1], k = 1
//输出：[0]

class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		if (arr.empty() || k == 0)
			return{};

		vector<int> res;
		sort(arr.begin(), arr.end());

		for (int i = 0; i < k; ++i)
		{
			res.push_back(arr[i]);
		}
		return res;
	}
};

//方法二：利用最大堆（priority_queue）。
//先将 arr 的前 k 个数入堆，因为是最大堆，所以堆顶的数一定是最大的。
//那么我们再从 arr 的第 k + 1 个元素迭代起，凡是遇到比当前堆顶元素小的，就将该元素 push 入堆并 pop 掉堆顶元素。
//注意，每次执行完第二步之后，堆会自动更新，以保证堆顶元素始终为堆中所有元素的最大值。

class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		if (arr.empty() || k == 0) { return{}; }
		vector<int> res(k);
		priority_queue<int> max_heap;

		for (int i = 0; i < k; ++i) { max_heap.push(arr[i]); } // 用 arr 的前 k 个数填充最大堆
		for (int i = k; i < arr.size(); ++i) {
			if (arr[i] < max_heap.top()){
				max_heap.pop();
				max_heap.push(arr[i]); // 循环更新最大堆
			}
		}
		for (int i = 0; i < k; ++i) {
			res[i] = max_heap.top(); // 填充 res
			max_heap.pop();
		}

		return res;
	}
};
