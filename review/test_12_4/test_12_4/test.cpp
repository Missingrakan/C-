#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

//�ַ���ѹ���������ַ��ظ����ֵĴ�������дһ�ַ�����ʵ�ֻ������ַ���ѹ�����ܡ�
//���磬�ַ���aabcccccaaa���Ϊa2b1c5a3������ѹ��������ַ���û�б�̣��򷵻�ԭ�ȵ��ַ�����
//����Լ����ַ�����ֻ������СдӢ����ĸ��a��z����
//
//ʾ��1 :
//
//���룺"aabcccccaaa"
//�����"a2b1c5a3"


class Solution {
public:
	string compressString(string S) {
		if ((int)S.length() == 0) return S; // �մ�����
		string ans = "";
		int cnt = 1;
		char ch = S[0];
		for (int i = 1; i < (int)S.length(); ++i){
			if (ch == S[i]) cnt++;
			else{
				ans += ch + to_string(cnt); // ע�� cnt ҪתΪ�ַ���
				ch = S[i];
				cnt = 1;
			}
		}
		ans += ch + to_string(cnt);
		return ans.length() >= S.length() ? S : ans;
	}
};

//����һ���� N �� N �����ʾ��ͼ������ÿ�����صĴ�СΪ 4 �ֽڡ��������һ���㷨����ͼ����ת 90 �ȡ�
//��ռ�ö����ڴ�ռ��ܷ�������
//ʾ�� 1:
//
//���� matrix =
//[
//	[1, 2, 3],
//	[4, 5, 6],
//	[7, 8, 9]
//],
//
//ԭ����ת�������ʹ���Ϊ:
//[
//	[7, 4, 1],
//	[8, 5, 2],
//	[9, 6, 3]
//]

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		// C++ ����� = ������ֵ��������õ�һ���µ�����
		auto matrix_new = matrix;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				matrix_new[j][n - i - 1] = matrix[i][j];
			}
		}
		// ����Ҳ��ֵ����
		matrix = matrix_new;
	}
};

//��дһ���㷨����M �� N������ĳ��Ԫ��Ϊ0���������ڵ����������㡣
//
//ʾ�� 1��
//���룺
//[
//	[1, 1, 1],
//	[1, 0, 1],
//	[1, 1, 1]
//]
//�����
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

//�ַ�����ת�����������ַ���s1��s2�����д������s2�Ƿ�Ϊs1��ת���ɣ����磬waterbottle��erbottlewat��ת����ַ�������
//
//ʾ��1 :
//
//���룺s1 = "waterbottle", s2 = "erbottlewat"
//�����True
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

 