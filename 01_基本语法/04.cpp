#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;


int main() {

	//#include<cstring.h>
	//strlen()	得到字符数组第一个\0前的字符的个数
	//int len = strlen(str);

	//strcmp()	返回两个字符串大小比较结果，按字典序(ascii)		
	//若str1<str2返回负整数	str1==str2返回0
	//int cmp = strcmp(str1, str2);

	//strcpy()	把str2复制给str1	包括\0
	//strcpy(str1, str2);

	//strcat()	把str2接到str1后面
	//strcat(str1, str2);\

	//---------------------------------------------------------------//

	//sscanf sprintf	处理字符串问题的利器
	//char str[100];
	//sscanf(str, "%d", &n);	把str中的内容以%d的格式写到n中
	//sprintf(str, "%d", n);	把n以%d的格式写到str中

	//printf和sprintf的计算都是从右向左进行的
	//int a = 5, b = 2;
	//printf("%d %d\n", b = a + 1, a = a + 1);	7 6
	//先计算a = a + 1		再计算b = a + 1;
}