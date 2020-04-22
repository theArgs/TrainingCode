#include <cstdio>
#include <cstring>

int main() {
	
	char ans[81] = {};

	fgets(ans, 81, stdin);	//多读了一个回车

	int len = strlen(ans);
	ans[len - 1] = '\0';
	len -= 1;

	for (int i = len - 1; i >= 0; i--) {
		if (ans[i] == ' ') {
			printf("%s ", ans + i + 1);
			ans[i] = '\0';
		}
		else {
			continue;
		}
	}
	printf("%s", ans);

	return 0;
}