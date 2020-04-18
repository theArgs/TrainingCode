#include <cstdio>

int main() {
	
	int a[200];
	int n = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &(a[i]));
	}

	int m = 0; 
	int index = -1;
	scanf("%d", &m);
	for (int i = 0; i < n; i++) {
		if (a[i] == m) {
			index = i;
			break;
		}
	}
	
	printf("%d\n", index);

	return 0;
}