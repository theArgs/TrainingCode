#include <cstdio>

int main() {
	
	int a, b, d;
	
	scanf("%d%d%d", &a, &b, &d);
	int sum = a + b;

	int ans[32], num = 0;

	do {	//进制转换
		ans[num++] = sum % d;
		sum /= d;
	} while (sum != 0);

	for (int i = num - 1; i >= 0; i--) {
		printf("%d", ans[i]);
	}

	return 0;
}