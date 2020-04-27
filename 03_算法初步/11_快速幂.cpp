#include <cstdio>

typedef long long LL;
/*
	快速幂
	若b是奇数，有a^b = a * a^(b-1)
	若b是偶数，有a^b = a^(b/2) * a^(b/2)

	复杂度logn
*/

//求 a^b%m，递归写法
//如果初始时a有可能大于m，则在进入函数前，就让a对m取模
LL binaryPow(LL a, LL b, LL m) {
	if (b == 0) return 1;

	if (b % 2 == 1) {	//可以用if(b & 1)	代替，更快一点
		return a * binaryPow(a, b - 1, m) % m;
	}
	else {
		LL mul = binaryPow(a, b / 2, m);
		return mul * mul % m;
	}
}

//快速幂迭代方式
/*
	对于a^b来说，b写成二进制，再b可以写成若干二次幂之和
	如	13的二进制为1101	13 = 2^3 + 2^2 + 2^0 = 8 + 4 + 1;
	则	a^13 = a^(8 + 4 + 1) = a^8 * a^4 + a^1;
	把	任意的a^b表示成 a^(2^k) ... a^(2^3) a^(2^2) a^(2^1) a^(a^0) 若干项的乘积
	即	如果b的二进制的i号位为1，则项 a^(2^i)就被选中
*/
//求 a^b%m，迭代写法
LL binaryPow2(LL a, LL b, LL m) {
	LL ans = 1;	//存放累计结果
	while (b > 0) {
		if (b & 1) {
			ans = ans * a % m;	//若末尾为1，ans乘上a的值
		}
		a = a * a % m;	//令a平方
		b >>= 1;	//b右移一位
	}
	return ans;
}

int main() {

	return 0;
}