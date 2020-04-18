#include <cstdio>
#include <cmath>
int main() {
	
	int n;
	char c;

	scanf("%d %c", &n, &c);
	
	int row = round(n * 1.0 / 2);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 || i == row-1) {
				printf("%c", c);
			}
			else {
				if (j == 0 || j == n-1) {
					printf("%c", c);
				}
				else {
					printf(" ");
				}
			}
		}
		printf("\n");
	}
	return 0;
}