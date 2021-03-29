#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

//

class Solution {
public:
	double myPow(double x, int n) {
		if (x == 1 || n == 0)
			return 1;

		if (n == 1)
			return x;

		double res = 1;
		if (n < 0)
		{
			n = -n;
			x = 1 / x;
		}

		while (n)
		{
			if (n & 1)
				res *= x;

			x *= x;
			n >>= 1;
		}

		return res;

		/*
		//err 2.00000 -2147483648
		while(n--)
		{
		res *= x;
		}
		*/
	}
};

void main()
{
	Solution s;
	int x = -2147483648;
	int y = 2147483648;
 	x = -x;
	s.myPow(2.00000, -2147483648);
}



////��ʵ��һ������������һ���������Զ����ƴ���ʽ����������������Ʊ�ʾ�� 1 �ĸ��������磬�� 9?��ʾ�ɶ������� 
////1001���� 2 λ�� 1����ˣ�������� 9����ú������ 2��
//
//class Solution {
//public:
//	int hammingWeight(uint32_t n) {
//		int count = 0;
//
//		while (n)
//		{
//			count++;
//			n = (n - 1)&n;
//		}
//
//		return count;
//	}
//
//	/*
//	int hammingWeight(uint32_t n) {
//		int count = 0;
//		unsigned int flag = 1;
//		while(flag)
//		{
//			if(n&flag)
//				count++;
//
//			flag <<= 1;
//		}
//
//		return count;
//	}
//	*/
//
//	/*
//	int hammingWeight(uint32_t n) {
//	int count = 0;
//
//	while(n)
//	{
//	if(n&1)
//	count++;
//
//	n >>= 1;
//	}
//
//	return count;
//	}
//	*/
//};
//
//void main()
//{
//	Solution s;
//	s.hammingWeight(11);
//}


/*
//������

// class Solution {
// public:
//     //̰���㷨
//     int cuttingRope(int n) {
//         if(n < 4) return n - 1;
//         long res = 1;//������long�������޷���%mod
//         //�������ã��������ı�������ȫ���ã����ݣ����ͣ�����
//         while(n > 4)//ѭ�����ࡡO(n)���Ӷ�
//         {
//             res *= 3;
//             res %= 1000000007;
//             n -= 3;
//         }
//         // ���n��ֵֻ�п����ǣ�2��3��4����2��3��4�ܵõ������˻�ǡǡ��������ֵ
//         // ��Ϊ2��3����Ҫ�ټ��ˣ����˷�����С����4����2x2�����ģ�2x2ǡ�ɵ���4
//         return res * n % 1000000007;
//     }
// };

class Solution {
public:
	int mod = (int)1e9 + 7;
	int cuttingRope(int n) {
		if (n < 4){
			return n - 1;
		}
		int count_3 = n / 3;
		if (n % 3 == 0){
			return (int)pow(3, count_3);
		}
		else if (n % 3 == 1){
			return (int)((pow(3, count_3 - 1) * 4) % mod);
		}
		else {
			return (int)((pow(3, count_3) * 2) % mod);//����count_3�����Ͳ�ͬ�������Ҫ���¶���pow()
		}
	}
	//�������� O(logn)���Ӷ�
private: 
	long pow(long base, int num)
	{
			 long res = 1;
			 while (num > 0)
			 {
				 if ((num & 1) == 1){//numΪ����ʱ //λ��0001
					 res *= base;
					 res %= mod;
				 }
				 base *= base;//numΪż��ʱ,baseƽ��
				 base %= mod;
				 num >>= 1;//����ĳ�2ȡ��,���һ��if�б�ʾ��res��
			 }
			 return res;
	}
};
*/