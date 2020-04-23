#include <cstdio>
#include <algorithm>
#include <cstring>

#include <vector>

using namespace std;

struct Student {
	char name[10];	
	int score;	//分数
}stu[2];

bool compare(Student a, Student b) {	//分数不同，则分数高的放在前面，否则按照姓名字典序放在前面
	//若比较结果中a应在b前面，返回1
	//否则返回0
	if (a.score > b.score) {
		return 1;
	}
	else if (a.score < b.score) {
		return 0;
	}
	else {
		if (strcmp(a.name, b.name) < 0) {
			return 1;
		}
		else {
			return 0;
		}

	}
	/*	或者写成

	if(a.score != b.score) {
		return a.score > b.score;
	}
	return strcmp(a.name, b.name) < 0;
	*/
}

int main() {
	
	//sort函数
	//#include <algorithm>
	//using namespace std;
	//格式：sort(首元素地址(必填)， 尾元素地址的下一个地址(必填), 比较函数(选填))	[首，尾)	默认递增
	
	int a[6] = { 9,4,2,5,6,-1 };
	sort(a, a + 4);	//对a[0]~a[3]从小到大排序
	sort(a, a + 6);	//对a[0]~a[5]从小到大排序

	strcpy(stu[0].name, "000");
	strcpy(stu[1].name, "111");

	stu[0].score = 99;
	stu[1].score = 100;

	//若要对结构体排序，要实现比较函数
	sort(stu, stu + 2, compare);

	vector<int> vi;
	vi.push_back(3);
	vi.push_back(1);
	vi.push_back(2);
	sort(vi.begin(), vi.end());	//对vector的排序	也可对string数组排序
	printf("%d %d %d", vi[0], vi[1], vi[2]);

	return 0;
}