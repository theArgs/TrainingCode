#include <cstdio>
#include <cstring>

const int MAXN = 100010;
const int MOD = 1000000007;

char str[MAXN];
int leftNumP[MAXN] = { 0 };	//每一位左侧(包含本身)P的个数

int main() {
	fgets(str,100010,stdin);	//读入字符串
	int len = strlen(str);
	str[len - 1] = '\n';
	len -= 1;

	for (int i = 0; i < len; i++) {
		if (i > 0) {	//如果不是0号位
			leftNumP[i] = leftNumP[i - 1];	//继承上一位的结果
		}

		if (str[i] == 'P') {	//当前位是P
			leftNumP[i]++;	//令leftNumP[i]加1
		}
	}

	int ans = 0, rightNumT = 0;	//ans为答案，rightNumT记录右边T的个数
	for (int i = len - 1; i >= 0; i--) {
		if (str[i] == 'T') {
			rightNumT++;
		}
		else if (str[i] == 'A') {
			ans = (ans + leftNumP[i] * rightNumT) % MOD;
		}
	}
	
	printf("%d\n", ans);

	return 0;
}