#include <cstdio>
#include <cmath>

const int maxn = 11;

//P为当前排列， hashTable记录整数x是否在P中
int n, P[maxn], hashTable[maxn] = { false };

int count = 0;

//当前处理第index位
void generateP(int index) {
	if (index == n + 1) {	//递归边界，已经处理完1~n位
		count++;	//能到达这里的一定是合法的
		return;
	}
	for (int x = 1; x <= n; x++) {	//第x行
		if (hashTable[x] == false) {	//如果第x行还没有皇后
			bool flag = true;
			for (int pre = 1; pre < index; pre++) {	//遍历之前的皇后
				//第index列皇后的行号为x，第pre列皇后的行号为P[pre]
				if (abs(index - pre) == abs(x - P[pre])) {
					flag = false;	//与之前的皇后在一条对角线，冲突
					break;
				}
			}
			if (flag) {	//如果可以放在第x行
				P[index] = x;	//令第index列皇后的行号为x
				hashTable[x] = true;	//第x行已被占用
				generateP(index + 1);	//递归处理第index+1行皇后
				hashTable[x] = false;	//还原
			}

		}
	}
}

int main() {
	n = 8;
	
	generateP(1);
	printf("%d\n", count);
	return 0;
}