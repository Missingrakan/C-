#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

//给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
//初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
//你可以假设 nums1 的空间大小等于 m + n，这样它就有足够的空间保存来自 nums2 的元素。

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = m - 1, j = n - 1, k = m + n - 1;
		while (i >= 0 && j >= 0)
		{
			if (nums1[i] > nums2[j])
				nums1[k--] = nums1[i--];
			else
				nums1[k--] = nums2[j--];
		}

		//任务主要是把二中元素放到1中，只要nums2都正确排序到nums1中则排序成功，不必考虑i
		while (j >= 0)
			nums1[k--] = nums2[j--];           
	}
};

//给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。
//如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。如果不存在最后一个单词，请返回 0 。
//说明：一个单词是指仅由字母组成、不包含任何空格字符的 最大子字符串。

class Solution {
public:
	int lengthOfLastWord(string s) {
		int len = 0;    //记录长度
		bool ifLast = false;
		for (int i = s.length() - 1; i >= 0; i--){
			if (s.at(i) == ' '){
				if (ifLast) break;
				continue;
			}

			len++;
			ifLast = true;
		}
		return len;
	}
};

#include <sstream>
class Solution {
public:
	//使用stringstream输入流，即重新输入该字符串，会自动按空格分隔字符串为单词。
	//while循环结束后得到最后一个单词，返回长度即可。
	int lengthOfLastWord(string s) {
		if (s.length() == 0)
			return 0;
		stringstream input(s);
		string str;
		while (input >> str);
		return str.length();
	}
};


//判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

//示例 1:		输入 : 121		输出 : true

class Solution {
public:
	bool isPalindrome(int x) {
		// 特殊情况：
		// 如上所述，当 x < 0 时，x 不是回文数。
		// 同样地，如果数字的最后一位是 0，为了使该数字为回文，
		// 则其第一位数字也应该是 0
		// 只有 0 满足这一属性
		if (x < 0 || (x % 10 == 0 && x != 0)) {
			return false;
		}

		int revertedNumber = 0;
		while (x > revertedNumber) {
			revertedNumber = revertedNumber * 10 + x % 10;
			x /= 10;
		}

		// 当数字长度为奇数时，我们可以通过 revertedNumber/10 去除处于中位的数字。
		// 例如，当输入为 12321 时，在 while 循环的末尾我们可以得到 x = 12，revertedNumber = 123，
		// 由于处于中位的数字不影响回文（它总是与自己相等），所以我们可以简单地将其去除。
		return x == revertedNumber || x == revertedNumber / 10;
	}
};

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;

		string str = to_string(x);
		int sz = str.size();
		int i = 0, j = sz - 1;
		while (i <= j)
		{
			if (str[i] != str[j])
				return false;

			i++;
			j--;
		}

		return true;
	}
};


//给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，
//判断第一个字符串 ransom 能不能由第二个字符串 magazines 里面的字符构成。
//如果可以构成，返回 true ；否则返回 false。
//(题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。杂志字符串中的每个字符只能在赎金信字符串中使用一次。)

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		int arr[26] = { 0 };
		//存magazine某个字母的个数
		for (auto m : magazine){
			arr[m - 'a']++;
			//减'a'是因为要把字符转换成数(利用ASCII)，例：'a'-'a' = 0; 'b' - 'a' = 1;
		}
		//遍历第一个字符串，如果找到 哈希表对应的个数减一  ，一直到某个数减到小于0就返回false
		for (auto r : ransomNote){
			arr[r - 'a']--;
			if (arr[r - 'a']<0){
				return false;
			}
		}
		return true;
	}
};

/*
#define N 2
#define M N+1
#define NUM (M+1)*M/2

int func(int a)
{
	int b;
	switch (a)
	{
	case 1: b = 30;
	case 2: b = 20;
	case 3: b = 16;
	default: b = 0;
	}
	return b;
}

int main()
{
	char str[] = "ABCD", *p = str;
	printf("%d\n", *(p + 4));
	printf("%d\n", NUM);
	printf("%d\n", func(1));
	int n = 2;
	printf("%d\n", n += n -= n*n);
	
}


int main()
{
	int i = 0, a = 0;
	while (i<20)
	{
		for (;;)
		{
			if ((i % 10) == 0) break;
			else i--;
		}
		i += 11; a += i;
	}
	printf("%d\n", a);
	return 0;
}
*/