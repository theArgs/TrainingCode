#include <cstdio>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}

void to_array(int n, int num[]) {	//将n的每一位放到num数组中
	for (int i = 0; i < 4; i++) {
		num[i] = n % 10;
		n /= 10;
	}
}

int to_number(int num[]) {
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		sum = sum * 10 + num[i];
	}
	return sum;
}

int main() {
	
	int n, MIN, MAX;	//MIN和MAX表示递增排序和递减排序后得到的最小值和最大值
	scanf("%d", &n);

	int num[5];
	while (1) {
		to_array(n, num);
		sort(num, num + 4);	//从小到大排序
		MIN = to_number(num);
		sort(num, num + 4, compare);
		MAX = to_number(num);
		n = MAX-MIN;
		printf("%04d - %04d = %04d\n", MAX, MIN, n);
		if (n == 0 || n == 6174) {
			break;
		}
	}

	return 0;
}