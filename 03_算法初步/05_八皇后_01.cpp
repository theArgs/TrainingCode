#include <cstdio>
#include <cmath>

const int maxn = 11;

//P为当前排列， hashTable记录整数x是否在P中
int n, P[maxn], hashTable[maxn] = { false };

int count = 0;

//当前处理第index位
void generateP(int index) {
	if (index == n + 1) {	//递归边界，已经处理完1~n位
		
		bool flag = true;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (abs(i - j) == abs(P[i] - P[j])) {
					flag = false;
				}
			}
		}
		if (flag) count++;
		return;
	}
	for (int x = 1; x <= n; x++) {	//枚举1-n，试图填入P[index]
		if (hashTable[x] == false) {	//如果x不在P[0]~P[index-1]中
			P[index] = x;	//令P的index位为x，即把x加入当前排列
			hashTable[x] = true;	//记录x已在P中
			generateP(index + 1);	//处理排列的第index+1位
			hashTable[x] = false;	//已处理完P[index] = x的子问题，还原状态
		}
	}
}

int main() {
	n = 8;
	
	generateP(1);
	printf("%d\n", count);
	return 0;
}