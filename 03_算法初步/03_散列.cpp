#include <cstdio>

const int maxn = 100010;

//如果统计出现次数，可换成int型
bool hashTable[maxn] = { false };	//其他默认值为0


int main() {
	
	int n, m, x;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n i++) {
		scanf("%d", &x);
		hashTable[x] = true;
	}

	for (int i = 0; i < m; i++) {
		scanf("%d", &x);
		if (hashTable[x] == true) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}

	return 0;
}