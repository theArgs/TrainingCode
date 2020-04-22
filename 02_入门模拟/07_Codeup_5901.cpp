#include <cstdio>
#include <cstring>


//判断str是否是回文串	前一半字符都等于对称位置的字符
bool judge(char str[]) {
	int len = strlen(str);
	for (int i = 0; i < len / 2; i++) {	//枚举前一半
		if (str[i] != str[len - 1 - i]) {
			return false;
		}
	}
	return true;
}

int main() {
	
	//长度不超过255的字符串，要多留一个位置给\0
	char str[256];
	while(scanf("%s", str)) {
		bool flag = judge(str);
		if (flag == true) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	
	return 0;
}