#include <cstdio>
#include <cstring>
/*
	大整数的存储
	整数的高位存储在数组的高位
	整数的低位存储在数组的低位
	运算时从整数的低位到高位进行枚举
	反转
*/

struct bign {
	int d[1000];
	int len;

	bign() {
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

bign change(char str[]) {	//从char[]转换为bign
	bign a;
	a.len = strlen(str);	//bign的长度就时字符串的长度
	for (int i = 0; i < a.len; i++) {
		a.d[i] = str[a.len - i - 1] - '0';	//逆着赋值
	}
	return a;
}

int compare(bign a, bign b) {	//比较a和b大小，a>b返回1，a==b返回0，a<b返回-1
	if (a.len > b.len) {
		return 1;
	}
	else if (a.len < b.len) {
		return -1;
	}
	else {
		for (int i = a.len - 1; i >= 0; i--) {
			if (a.d[i] > b.d[i]) {
				return 1;
			}
			else if (a.d[i] < b.d[i]) {
				return -1;
			}
		}
		return 0;
	}

}

bign add(bign a, bign b) {	//高精度a+b
	bign c;
	int carry = 0;	//进位
	for (int i = 0; i < a.len || i < b.len; i++) {	//以较长的为界限
		int temp = a.d[i] + b.d[i] + carry;	//两个对应位与进位相加
		c.d[c.len++] = temp % 10;	//个位数为该位结果
		carry = temp / 10;	//十位数为新的进位
	}
	if (carry != 0) {	//如果最后进位不为0，赋给结果的最高位
		c.d[c.len++] = carry;
	}
	return c;
}

bign sub(bign a, bign b) {	//高精度a-b
	bign c;
	for (int i = 0; i < a.len || i < b.len; i++) {	//以较长的为界限
		if (a.d[i] < b.d[i]) {	//如果不够减
			a.d[i + 1]--;	//向高位借位
			a.d[i] += 10;	//当前位加10
		}
		c.d[c.len++] = a.d[i] - b.d[i];	//减法结果为当前位结果
	}
	while (c.len-1>=1 && c.d[c.len-1] == 0) {
		c.len--;	//去除最高位的0，同时至少保留一位最低位
	}
	return c;
}

bign multi(bign a, int b) {	//高精度与低精度乘法
	bign c;
	int carry = 0;	//进位
	for (int i = 0; i < a.len; i++) {
		int temp = a.d[i] * b + carry;	//把int视为整体
		c.d[c.len++] = temp % 10;	//个位作为该位结果
		carry = temp / 10;	//高位作为新的进位
	}
	while (carry != 0) {	//乘法的进位可能有多位，用while
		c.d[c.len++] = carry % 10;
		carry /= 10;
	}
	return c;
}

bign divide(bign a, int b, int& r) {	//高精度与低精度除法，r为余数
	bign c;
	c.len = a.len;	//被除数的每一位和商的每一位一一对应，先令长度相等
	for (int i = a.len - 1; i >= 0; i--) {	//从高位开始
		r = r * 10 + a.d[i];	//和上一位遗留的余数组合
		if (r < b) {
			c.d[i] = 0;	//不够除，该位为0
		}
		else {	//够除
			c.d[i] = r / b;	//商
			r = r % b;	//获得新的余数
		}
	}
	while (c.len - 1 >= 1 && c.d[c.len - 1] == 0) {
		c.len--;
	}
	return c;
}
	

void print(bign a) {	//输出bign
	for (int i = a.len - 1; i >= 0; i--) {
		printf("%d", a.d[i]);
	}

}

int main() {
	char str1[1000], str2[1000];
	scanf("%s%s", str1, str2);
	bign a = change(str1);
	bign b = change(str2);
	print(add(a, b));
	return 0;
}