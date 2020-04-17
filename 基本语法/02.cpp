#include <iostream>
#include <cstdio>
using namespace std;


int main() {
	int n = 0;

	if (n) {	//相当于n!=0
		;
	}
	if (!n) {	//相当于n==0
		;
	}

	//c++新支持在for表达式一中定义变量
	for (int i = 0; i < 5; i++) {
		;
	}


	L:for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 5; j++) {
			if (j==2) {
				//c++中break只能跳出一层
				break;
			}
		}
	}
}