#include <cstdio>

//普通二分查找，随机一个值匹配的位置
int binarySearch(int A[], int left, int right, int x) {
	int mid;
	while (left <= right) {

		mid = (left + right) / 2;
		//如果欲查找元素序列靠后，可能(left + right)超过int导致溢出时
		//mid = left + (right - left) / 2;
		if (A[mid] == x) {
			return mid;
		}
		else if (A[mid] > x) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return -1;
}

//返回第一个大于等于x的元素的位置
int lower_bound(int A[], int left, int right, int x) {
	int mid;
	while (left < right) {	//当left==right时，夹出唯一的位置，即是结果
		mid = (left + right) / 2;
		if (A[mid] >= x) {	//中间的数大于等于x，则第一个大于等于x的元素一定在mid处或mid的左侧
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
	return left;
}

//返回第一个大于x的元素的位置
int upper_bound(int A[], int left, int right, int x) {
	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (A[mid] > x) {	//中间的数大于x，则第一个大于x的元素一定在mid处或mid左侧
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
	return left;
}

int main() {

	const int n = 10;
	int A[n] = { 1,3,4,6,7,8,10,11,12,15 };
	printf("%d %d\n", binarySearch(A, 0, n - 1, 6), binarySearch(A, 0, n - 1, 9));

	return 0;
}

//如果想要寻找最后一个满足“条件C"的元素的位置
//可以先求出第一个满足“条件!C”的元素位置，然后将该位置减一