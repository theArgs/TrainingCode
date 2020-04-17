#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define pi01 3.14					//宏定义(宏替换)	编译时pi01会被替换
#define ADD(a, b)	((a) + (b))		//注意宏定义陷阱

int main() {
	int num;								//绝对值在10^9以内的整数		或32位整数	都可以定义成int型	输出格式%d
	long long bignum;						//绝对值10^18以内	或64位整数	要用long long
	long long bignum2 = 123456789012345LL;	//若要赋初值则初值后加LL
	double d;								//输出格式%f

	//由''括起来的	只能有一个字符	\n换行		\0空字符NULL(不是空格) ascii码为0
	char c;				//小写字母比大写字母ASCII码大32		0:48	A:65	a:97		输出格式%c
	char str[20];		//字符串(以'\0'结尾)		输出格式%s	若为字符数组循环用%c输出
	bool flag = true;	//布尔型		可用true或false或整型常量(非零为true)赋值	输出格式%d
	const double pi02 = 3.14;
	//printf("%f", ADD(pi01, pi02));		6.280000

	//位运算
	//无穷大可设置为2^31-1	0x3fffffff	这里用2^30-1避免相加超过int		必须加括号，位运算优先级低于算数运算符
	const int INF = (1 << 30) -1;		
	const int INF02 = 0x3fffffff;
	//printf("%d", INF02);	1073741823

	int n, m;
	n = m = 5;	//可以连续等号赋值
	n /= m;	//复合赋值运算可以加快编译速度，提高代码可读性

	//---------------------------------------------------------------------------------------------------------------------------//
	/*scanf
		int				%d	scanf("%d", &n);
		long long		%lld
		double			%lf
		char			%c
		字符串			%s	scanf("%s", str);	没有取地址符，数组名本身代表第一个元素的地址

		scanf("%d:%d:%d", &hh, &mm, &&ss);		双引号的内容是整个输入，把数据变成对应格式存储
		scanf("%d%d", &a, &b);					若用空格隔开，可不加空格

		除了%c，其他格式符以空白符(空格、Tab)作为结束判断
		%s以空格和换行作为读入结束标志 %c可以读入空格和换行
		scanf("%d%c%s", &a, &c, str);			输入 1 a bcd 时	a为1，c为空格，str为a
	*/

	/*printf
		int				%d		printf("%d", n);
		long long		%lld
		double			%f		这里与scanf不同
		char			%c
		字符串			%s		printf("%s", str);		
		输出%			%%	
		输出\			\\

		格式
			%md			不足m位的以m位右对齐输出，高位空格补齐，本身若超过m位，则保持原样
			%0md		不足m位时前面补足0而不是空格
			%.mf		让浮点数保留m位小数输出，规则是四舍六入五成双
	*/

	/*
		char c;
		c = getchar();	读取一个字符
		getchar();		可以识别换行符
		putchar(c);		输出一个字符不会自动换行
	*/

	typedef long long LL;	//给复杂的数据类型起别名
	LL ;

	//#include<cmath>
	d = fabs(pi01);			//可对double取绝对值
	d = floor(pi01);		//double向下取整
	d = ceil(pi01);			//double向上取整
	d = pow(d, pi01);		//返回d^pi01		两个参数都为double
	d = sqrt(d);			//返回double型的算数平方根
	d = log(d);				//返回以e为底的对数		若要为任意底，则使用换底公式 log(a)b = log(e)b / log(e)a
	d = sin(d);				//返回正弦值，参数为弧度制		类似的 cos(double x)  tan(double x)
	//pi的较精确值为acos(-1.0) 因为cos(pi)=-1
	d = asin(1);			//返回double型的反正弦值		类似的 acos(double x)  atan(double x)
	d = round(d);			//四舍五入返回double类型的取整后的值
}