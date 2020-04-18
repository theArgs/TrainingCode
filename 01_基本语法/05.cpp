#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void change(int a[], int b[][5]) {
	;
}

void change(int& x) {
	;
}

void change(int*& p1, int*& p2) {
	;
}

struct Point2 {
	int m;
	int n;
};

int main() {

	//函数的参数可以是数组，参数中数组的第一维不需要填写长度，若是二维则第二维要填写长度
	//实际调用时填写数组名	函数中对数组元素的修改等同对原数组元素的修改
	int a[5];
	int b[3][5];
	change(a,b);
	//数组不能作为返回类型，若想返回数组，则需要将返回的数组作为参数传入

	//指针是一个unsigned类型的整数
	//int* p1, p2;	p1是int*类型的，p2是int类型的	*只会结合第一个变量名
	//int *p = &a;
	//*p = 10;	p没有改变，改变的是p指向的变量
	//指针可以加减法，1是一个地址偏移的距离		对int *的p来说，p+1是p所指向的int型变量的下一个int型变量的地址
	//两个指针相减，等价于求两个指针间相差了几个元素

	//指针类型作为函数参数，修改这个地址中的元素，原来的数据确实地被改变

	//c++中引用是给变量起别名，对引用变量的操作就是对原变量的操作
	int x = 1;
	change(x);
		
	/*思考
		形参与实参传递时应该类似于赋值
		例如
		int x,y;
		
		void fun(int a, int b);
			fun(x,y)
			传递时int a = x, b = y;		操作内部a,b不影响外部
		void fun(int* a, int* b);
			fun(&x,&y)
			传递时int *a = &x, *b = &y;	用*a,*b操作会影响外部数据
		void fun(int &a, int &y);
			fun(x,y)
			传递时int &a = x, &b = y;		起别名，等同于操作x,y
	*/

	//指针的引用，可以修改指针本身和指针指向的变量
	int* p1 = a, * p2 = a;
	change(p1, p2);

	//引用是产生变量的别名，常量不能使用引用
	//change(&a, &a);
	//是错误的，必须先用两个变量存放&a,&b然后作为参数传入

	struct node {
		int n;
		node* next;	//结构体里不能定义本身，但是可以定义自身类型的指针变量
	};

	node no;

	struct studentInfo {
		int id;
		char name[20];
		char gender;
		studentInfo* next;
	}stu, *p;

	//访问时
	/*
		stu.id
		stu.name
		stu.next
		p->id
		p->name
		p->next
	*/
	
	//结构体的初始化
	struct Point {
		int x, y;
		Point() {	////构造函数用以不经初始化的定义	
			x = 0;
			y = 0;
		}
		Point(int _x, int _y) :x(_x), y(_y) {};	//可以简化成一行
	};

	Point p3;					//隐式构造函数时使用了未初始化的局部变量	
								//当显式给出构造函数却没有语句时，x,y为随机值
	Point q = Point(1, 2);
	Point *q2 = new Point();	//若构造函数中不赋值，局部类型new出来也是随机值
								//隐式构造函数时可以new，不会报错，x,y为随机值

	Point2* p5 = new Point2();	//没有构造函数时，全局类型new出来初始值为0
}