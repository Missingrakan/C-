#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//����һ�������������е��������� nums����һ��Ŀ��ֵ target���ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ�á�
//��������в�����Ŀ��ֵ target������?[-1, -1]��

class Solution {
private:
	int findFitstPosition(vector<int> &nums, int target) {
		int size = nums.size();
		int left = 0;
		int right = size - 1;
		while (left < right) 
		{
			int mid = left + (right - left) / 2;
			if (nums[mid] < target) 
				left = mid + 1;
			else if (nums[mid] == target)
				right = mid;
			else 
				// nums[mid] > target
				right = mid - 1;
		}
		if (nums[left] != target) 
			return -1;
		return left;
	}

	int findLastPosition(vector<int> &nums, int target) {
		int size = nums.size();
		int left = 0;
		int right = size - 1;
		while (left < right) {
			int mid = left + (right - left + 1) / 2;
			if (nums[mid] > target) {
				right = mid - 1;
			}
			else if (nums[mid] == target){
				left = mid;
			}
			else {
				// nums[mid] < target
				left = mid + 1;
			}
		}
		if (nums[left] != target) {
			return -1;
		}
		return left;
	}


public:
	vector<int> searchRange(vector<int> &nums, int target) {
		int size = nums.size();
		if (size == 0) {
			return{ -1, -1 };
		}
		int fitstPosition = findFitstPosition(nums, target);

		if (fitstPosition == -1) {
			return{ -1, -1 };
		}
		int lastPosition = findLastPosition(nums, target);
		return{ fitstPosition, lastPosition };
	}
};

void main()
{
	vector<int> v = { 5, 7, 7, 8, 8, 10 };
	Solution s;
	s.searchRange(v, 8);
}

/*
class Solution {
public:
	int binarySearch(vector<int>& nums, int target, bool lower) {
		int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
		while (left <= right) 
		{
			int mid = (left + right) / 2;
			if (nums[mid] > target || (lower && nums[mid] >= target)) 
			{
				right = mid - 1;
				ans = mid;
			}
			else {
				left = mid + 1;
			}
		}
		return ans;
	}

	vector<int> searchRange(vector<int>& nums, int target) {
		int leftIdx = binarySearch(nums, target, true);
		int rightIdx = binarySearch(nums, target, false) - 1;
		if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target) {
			return vector<int>{leftIdx, rightIdx};
		}
		return vector<int>{-1, -1};
	}
};
*/

/*

//������ʵ��һ��?myAtoi(string s)?������ʹ���ܽ��ַ���ת����һ�� 32 λ�з������������� C / C++ �е� atoi ��������
//����?myAtoi(string s) ���㷨���£�
//
//�����ַ������������õ�ǰ���ո�
//����һ���ַ������軹δ���ַ�ĩβ��Ϊ�����Ǹ��ţ���ȡ���ַ�������У��� ȷ�����ս���Ǹ������������� ������߶������ڣ���ٶ����Ϊ����
//������һ���ַ���ֱ��������һ���������ַ��򵽴�����Ľ�β���ַ��������ಿ�ֽ������ԡ�
//��ǰ�沽��������Щ����ת��Ϊ����������"123" -> 123�� "0032" -> 32�������û�ж������֣�������Ϊ 0 ����Ҫʱ���ķ��ţ��Ӳ��� 2 ��ʼ����
//������������� 32 λ�з���������Χ[?231, 231?? 1] ����Ҫ�ض����������ʹ�䱣���������Χ�ڡ�������˵��С�� ?231 ������Ӧ�ñ��̶�Ϊ ?231 ������ 231?? 1 ������Ӧ�ñ��̶�Ϊ 231?? 1 ��
//����������Ϊ���ս����

//ע�⣺
//�����еĿհ��ַ�ֻ�����ո��ַ� ' ' ��
//��ǰ���ո�����ֺ�������ַ����⣬������� �κ������ַ���
//
//ʾ��?1��
//
//���룺s = "42"
//�����42
//���ͣ��Ӵֵ��ַ���Ϊ�Ѿ�������ַ�����������ǵ�ǰ��ȡ���ַ���
//�� 1 ����"42"����ǰû�ж����ַ�����Ϊû��ǰ���ո�
//^
//�� 2 ����"42"����ǰû�ж����ַ�����Ϊ���ﲻ���� '-' ���� '+'��
//^
//�� 3 ����"42"������ "42"��
//^
//�����õ����� 42 ��
//���� "42" �ڷ�Χ[-231, 231 - 1] �ڣ����ս��Ϊ 42 ��
//ʾ��?2��
//
//���룺s = "   -42"
//����� - 42
//���ͣ�
//�� 1 ����"   -42"������ǰ���ո񣬵����ӵ���
//^
//�� 2 ����"   -42"������ '-' �ַ������Խ��Ӧ���Ǹ�����
//^
//�� 3 ����"   -42"������ "42"��
//^
//�����õ����� - 42 ��
//���� "-42" �ڷ�Χ[-231, 231 - 1] �ڣ����ս��Ϊ - 42 ��
//ʾ��?3��
//
//���룺s = "4193 with words"
//�����4193
//���ͣ�
//�� 1 ����"4193 with words"����ǰû�ж����ַ�����Ϊû��ǰ���ո�
//			^
//�� 2 ����"4193 with words"����ǰû�ж����ַ�����Ϊ���ﲻ���� '-' ���� '+'��
//			^
//�� 3 ����"4193 with words"������ "4193"��������һ���ַ�����һ�����֣����Զ���ֹͣ��
//				^
//�����õ����� 4193 ��
//���� "4193" �ڷ�Χ[-231, 231 - 1] �ڣ����ս��Ϊ 4193 ��
//ʾ��?4��
//
//���룺s = "words and 987"
//�����0
//���ͣ�
//�� 1 ����"words and 987"����ǰû�ж����ַ�����Ϊû��ǰ���ո�
//			^
//�� 2 ����"words and 987"����ǰû�ж����ַ�����Ϊ���ﲻ���� '-' ���� '+'��
//			^
//�� 3 ����"words and 987"�����ڵ�ǰ�ַ� 'w' ����һ�����֣����Զ���ֹͣ��
//			^
//�����õ����� 0 ����Ϊû�ж����κ����֡�
//���� 0 �ڷ�Χ[-231, 231 - 1] �ڣ����ս��Ϊ 0 ��
//ʾ��?5��
//
//���룺s = "-91283472332"
//����� - 2147483648
//���ͣ�
//�� 1 ����"-91283472332"����ǰû�ж����ַ�����Ϊû��ǰ���ո�
//^
//�� 2 ����"-91283472332"������ '-' �ַ������Խ��Ӧ���Ǹ�����
//^
//�� 3 ����"-91283472332"������ "91283472332"��
//^
//�����õ����� - 91283472332 ��
//���� - 91283472332 С�ڷ�Χ[-231, 231 - 1] ���½磬���ս�����ض�Ϊ - 231 = -2147483648 ��

class Solution {
public:
	int myAtoi(string s) {
		//�����ո�
		size_t i = 0;
		while (i < s.size() && s[i] == ' ')
			i++;
		if (i == s.size())
			return 0;

		//�ж����޷���
		int flag = 1;
		if (s[i] == '-')
		{
			flag = -1;
			i++;
		}
		else if (s[i] == '+')
			i++;

		//���Ƿ���Ҳ�������֣�ֱ�ӷ���
		else if (!isdigit(s[i]))
			return 0;

		//��������Ч������
		int num = 0;
		while (isdigit(s[i]) && (i < s.size()))
		{
			//INT_MAX < 10*num + (s[i]-'0')  ����жϲ��У���Ϊ��ʱ�����num��Ϊint�޷�������(�����������)������С���ɾ��ǽ������INT_MAX��2147483647
			if ((INT_MAX - (s[i] - '0')) / 10 < num)
			{
				return flag == -1 ? flag*INT_MAX - 1 : INT_MAX;
			}
			num = 10 * num + (s[i] - '0');
			i++;
		}

		return flag*num;
	}
};

*/