#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

//字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。
//比如，字符串aabcccccaaa会变为a2b1c5a3。若“压缩”后的字符串没有变短，则返回原先的字符串。
//你可以假设字符串中只包含大小写英文字母（a至z）。
//
//示例1 :
//
//输入："aabcccccaaa"
//输出："a2b1c5a3"


class Solution {
public:
	string compressString(string S) {
		if ((int)S.length() == 0) return S; // 空串处理
		string ans = "";
		int cnt = 1;
		char ch = S[0];
		for (int i = 1; i < (int)S.length(); ++i){
			if (ch == S[i]) cnt++;
			else{
				ans += ch + to_string(cnt); // 注意 cnt 要转为字符串
				ch = S[i];
				cnt = 1;
			}
		}
		ans += ch + to_string(cnt);
		return ans.length() >= S.length() ? S : ans;
	}
};

//给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。
//不占用额外内存空间能否做到？
//示例 1:
//
//给定 matrix =
//[
//	[1, 2, 3],
//	[4, 5, 6],
//	[7, 8, 9]
//],
//
//原地旋转输入矩阵，使其变为:
//[
//	[7, 4, 1],
//	[8, 5, 2],
//	[9, 6, 3]
//]

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		// C++ 这里的 = 拷贝是值拷贝，会得到一个新的数组
		auto matrix_new = matrix;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				matrix_new[j][n - i - 1] = matrix[i][j];
			}
		}
		// 这里也是值拷贝
		matrix = matrix_new;
	}
};

//编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。
//
//示例 1：
//输入：
//[
//	[1, 1, 1],
//	[1, 0, 1],
//	[1, 1, 1]
//]
//输出：
//[
//	[1, 0, 1],
//	[0, 0, 0],
//	[1, 0, 1]
//]

void setZeroes(vector<vector<int>> & matrix) {
	int i = 0;
	int j = 0;
	int k = 0;
	vector<vector<int>> mZero;

	mZero = matrix;
	// find zero
	for (i = 0; i < mZero.size(); ++i) {
		for (j = 0; j < mZero[i].size(); ++j) {
			if (0 == mZero[i][j]) {
				for (k = 0; k < matrix[i].size(); ++k) {
					matrix[i][k] = 0;
				}

				for (k = 0; k < matrix.size(); ++k) {
					matrix[k][j] = 0;
				}
			}
		}
	}

	return;
}

//字符串轮转。给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成（比如，waterbottle是erbottlewat旋转后的字符串）。
//
//示例1 :
//
//输入：s1 = "waterbottle", s2 = "erbottlewat"
//输出：True
//

class Solution {
public:
	bool isFlipedString(string s1, string s2) {
		int m = s1.size(), n = s2.size();
		if (m != n) return false;
		if (m == 0) return true;
		for (int i = 0; i < m; i++){
			if (s1[i] == s2[0]){
				if (s1.substr(0, i) == s2.substr(m - i) && s1.substr(i) == s2.substr(0, m - i))
					return true;
			}
		}
		return false;
	}
};

class Solution {
public:
	bool isFlipedString(string s1, string s2) {
		return s1.size() == s2.size() && (s1 + s1).find(s2) != -1;
	}
};

 