#include <cstdio>
#include <cmath>
//1既不是素数，也不是质数

bool isPrime(int n) {
	if (n <= 1) {	//特判
		return false;	
	}
	int sqr = (int)sqrt(1.0 * n);	//根号n
	for (int i = 2; i <= sqr; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;	//n是素数
}

//筛法获取素数表	对于每一个素数，筛去他的所有倍数
const int maxn = 101;
int prime[maxn], pNum = 0;
bool p[maxn] = { 0 };
void Find_Prime() {
	for (int i = 2; i < maxn; i++) {
		if (p[i] == false) {
			prime[pNum++] = i;
			for (int j = i + i; j < maxn; j += i) {
				p[j] = true;
			}
		}
	}
}


int main() {
	Find_Prime();
	for (int i = 0; i < pNum; i++) {
		printf("%d ", prime[i]);
	}

	return 0;
}