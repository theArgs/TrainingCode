#include <cstdio>

int main() {
	
	int score[100001] = {};

	int n = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int index = 0;
		int tscore = 0;

		scanf("%d%d", &index, &tscore);

		score[index] += tscore;
	}

	int max = 0;
	int mindex = 0;
	for (int i = 0; i < n; i++) {
		if (score[i+1] > max) {
			max = score[i + 1];
			mindex = i + 1;
		}
	}

	printf("%d %d\n", mindex, max);
	return 0;
}