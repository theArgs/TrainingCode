#include <cstdio>

/*
	一个有序序列，寻找两个位置，使得相加和恰为M
	对于a[i] a[j] i < j
	若 a[i] + a[j] > M	可知a[i] + a[j+1] > M 且 a[i+1] + a[j] > M ...
	因此i和j互相牵制
*/

/*
	如果满足a[i]+a[j] == M 找到了一组方案 因此剩余的方案在[i+1,j-1]中产生
	如果a[i]+a[j] > M 则剩余的方案只可能在[i,j-1]中产生
	如果a[i]+a[j] < M 则剩余的方案只可能在[i+1,j]中产生
*/

int main() {
	int a[6] = { 1,2,3,4,5,6 };
	int i = 0, j = 5, m = 8;

	while (i < j) {
		if (a[i] + a[j] == m) {
			printf("%d %d\n", i, j);
			i++;
			j--;
		}
		else if (a[i] + a[j] < m) {
			i++;
		}
		else {
			j--;
		}
	}

	return 0;
}