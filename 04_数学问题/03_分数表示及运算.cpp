#include <cstdio>
#include <cmath>
int gcd(int a, int b) {	//最大公约数
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}
/*
	1.使down为非负数，如果分数为负，令up为负
	2.如果分数恰好为0，规定其分子为0，分母为1
	3.分子和分母没有除了1以外的公约数
*/
struct Fraction {	//分数	若乘除法可能超出范围，分子分母使用long long
	int up, down;	//分子、分母
};

Fraction reduction(Fraction result) {	//分数的化简
	/*
		1.如果down为负数，令up和down都变为相反数
		2.如果up为0，令down为1
		3.求出分子分母绝对值的最大公约数d，分子分母同时除以d
	*/
	if (result.down < 0) {
		result.up = -result.up;
		result.down = -result.down;
	}
	if (result.up == 0) {
		result.down = 1;
	}
	else {
		int d = gcd(abs(result.up), abs(result.down));
		result.up /= d;
		result.down /= d;
	}
	return result;
}

Fraction add(Fraction f1, Fraction f2) {	//分数加法
	Fraction result;
	result.up = f1.up * f2.down + f2.up * f1.down;
	result.down = f1.down + f2.down;
	return reduction(result);
}

Fraction minu(Fraction f1, Fraction f2) {	//分数减法
	Fraction result;
	result.up = f1.up * f2.down - f2.up * f1.down;
	result.down = f1.down * f2.down;
	return reduction(result);
}

Fraction multi(Fraction f1, Fraction f2) {	//分数乘法
	Fraction result;
	result.up = f1.up * f2.up;
	result.down = f1.down * f2.down;
	return reduction(result);
}

Fraction divide(Fraction f1, Fraction f2) {	//分数除法
	Fraction result;
	result.up = f1.up * f2.down;
	result.down = f1.down * f2.up;
	return reduction(result);
}

void showResult(Fraction r) {	//分数输出
	/*
		1.化简
		2.若分母为1，说明为整数，省略分母的输出
		3.up的绝对值大于down(假分数)，分别输出整数部分、up、down
		4.其他情况原样输出
	*/
	r = reduction(r);
	if (r.down == 1) {
		printf("%lld", r.up);
	}
	else if (abs(r.up)>r.down) {
		printf("%d %d/%d", r.up / r.down, abs(r.up) % r.down, r.down);
	}
	else {
		printf("%d/%d", r.up, r.down);
	}
}



int main() {

	return 0;
}