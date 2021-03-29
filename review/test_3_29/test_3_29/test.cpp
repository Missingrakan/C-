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



////请实现一个函数，输入一个整数（以二进制串形式），输出该数二进制表示中 1 的个数。例如，把 9?表示成二进制是 
////1001，有 2 位是 1。因此，如果输入 9，则该函数输出 2。
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
//剪绳子

// class Solution {
// public:
//     //贪婪算法
//     int cuttingRope(int n) {
//         if(n < 4) return n - 1;
//         long res = 1;//必须是long，否则无法用%mod
//         //尽可能用３，即３的倍数的数全部用３的幂，４和２除外
//         while(n > 4)//循环求余　O(n)复杂度
//         {
//             res *= 3;
//             res %= 1000000007;
//             n -= 3;
//         }
//         // 最后n的值只有可能是：2、3、4。而2、3、4能得到的最大乘积恰恰就是自身值
//         // 因为2、3不需要再剪了（剪了反而变小）；4剪成2x2是最大的，2x2恰巧等于4
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
			return (int)((pow(3, count_3) * 2) % mod);//３和count_3的类型不同，因此需要重新定义pow()
		}
	}
	//快速求幂 O(logn)复杂度
private: 
	long pow(long base, int num)
	{
			 long res = 1;
			 while (num > 0)
			 {
				 if ((num & 1) == 1){//num为奇数时 //位与0001
					 res *= base;
					 res %= mod;
				 }
				 base *= base;//num为偶数时,base平方
				 base %= mod;
				 num >>= 1;//经典的除2取整,多的一在if中表示给res了
			 }
			 return res;
	}
};
*/