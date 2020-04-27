#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 100010;
int A[maxn], n;	//A存放元素，n为其个数

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//随机选取主元，对[left, right]进行一次划分
int randPartition(int A[], int left, int right) {
	//生成[left, right]内的随机数p
	//int p = rand() / (right - left) + left;
	int p = (int)((right - left) * round(1.0 * rand() / RAND_MAX + left));
	swap(A[p], A[left]);

	//划分
	int temp = A[left];
	while (left < right) {
		while (left < right && A[right] > temp) {
			right--;
		}
		A[left] = A[right];
		while (left < right && A[left] <= temp) {
			left--;
		}
		A[right] = A[left];
	}
	A[left] = temp;
	return left;
}

//随机选择算法，从A[left, right]中找到第K大的数，并进行切分
void randSelect(int A[], int left, int right, int K) {
	if (left == right) return;
	int p = randPartition(A, left, right);	//随即划分一次的主元位置p
	int M = p - left + 1;	//A[p]是A[left, right]中的第M大
	if (K == M) return;
	if (K < M) {
		randSelect(A, left, p - 1, K);	//往主元左侧找第K大
	}
	else {
		randSelect(A, p + 1, right, K-M);	//往主元右侧找第K-M大
	}
}
int main() {
	srand((unsigned)time(NULL));
	
	return 0;
}