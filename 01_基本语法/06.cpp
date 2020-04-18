#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	//对于考试而言，不推荐使用cin与cout	对于大量数据情况下表现得非常糟糕

	//浮点数比较
	//计算机中浮点数的存储有误差，而==操作是完全相同才能判定为true
	//浮点数相差小于10^(-8)即认为相等

	//科学计数法		men 其中 e(代表指数)	表示m乘以10的n次幂

	double db = 1.23;

	//db == 1.23
	(fabs(db - 1.23) < 1e-8);	//是一个bool值

		
	//db != 1.23
	!(fabs(db - 1.23) < 1e-8);

	//db > 1.23
	(db - 1.23) > 1e-8;	//a > b	即是在误差的扰动范围之外大于b	即a > b + eps

	//db < 1.23
	(db - 1.23) < -1e-8;

	//db >= 1.23
	(db - 1.23) > -1e-8;	//a >= b	在扰动范围内都大于等于	即大于b-eps

	//db <= 1.23
	(db - 1.23) < 1e-8;		//a <= b	在扰动范围内都小于等于	即小于b+eps

	//圆周率	cos(pi) = -1;
	double Pi = acos(-1.0);

	//scanf读取有返回值，返回值为成功读入参数的个数
	//当读取到文件结尾时，读取失败，会返回-1，C中使用EOF代表-1
	int n;
	//while (scanf("%d", &n) != EOF);

}