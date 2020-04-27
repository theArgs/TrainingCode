#include <cstdio>

const int maxn = 1000001;
int prime[maxn], num = 0;
bool p[maxn] = { 0 };

void Find_Prime(int n) {
	for (int i = 2; i < maxn; i++) {
		if (p[i] == false) {
			prime[num++] = i;
			if (num >= n) {	//只要n个素数，超过时跳出
				break;
			}
			for (int j = i + i; j < maxn; j += i) {
				p[j] = true;
			}
		}
	}
}

struct factor {
	int x, cnt;	//x为质因子，cnt为其个数
}fac[10];	//2*3*5*7*11*13*17*19*23*29已经超过int范围，所以数组开到10即可

/*
	对于一个正整数n来说，如果存在[2,n]范围内的质因子，
	要么质因子全部小于等于sqrt(n);
	要么只存在一个大于sqrt(n)的质因子，其余的都小于等于sqrt(n)
*/

int main() {
	
	//枚举1~sqrt(n)范围所有质因子p，判断p是否是n的因子
	/*
		若p是n的因子，则给fac数组中增加质因子p，并初始化为0
		只要p还是n的因子，就让n不断除以p，每次操作令p的个数加1
		直到p不再是n的因子为止
	*/
	/*
		p不是n的因子，直接跳过
	*/
	//若上述步骤后n仍大于1，则n有且仅有一个大于sqrt(n)的质因子
	//将其加入fac数组，并令其个数为1
	
	return 0;
}