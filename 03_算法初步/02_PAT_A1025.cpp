#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct Student {
	char id[15];		//准考证号
	int score;			//分数
	int location_number;//考场号
	int local_rank;		//考场内排名
}stu[30010];

bool compare(Student a, Student b) {
	if (a.score > b.score) {
		return 1;
	}
	else if(a.score < b.score) {
		return 0;
	}
	else {
		if (strcmp(a.id, b.id) < 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
}

int main() {
	
	int n, k, num = 0;	//num为考生总数
	scanf("%d", &n);	//考场数
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);	//该考场人数
		for (int j = 0; j < k; j++) {
			scanf("%s %d", stu[num].id, &stu[num].score);
			stu[num].location_number = i;	//考场号为i
			num++;	//总考生数加1
		}

		sort(stu + num - k, stu + num, compare);	//对该考场考生排序
		stu[num - k].local_rank = 1;	//该考场第一名local_rank为1
		for (int j = num - k + 1; j < num; j++) {	//剩余考生
			if (stu[j].score == stu[j - 1].score) {	//如果与前一名同分
				stu[j].local_rank = stu[j - 1].local_rank;	//排名也相同
			}
			else {	//否则为该考生前的人数
				stu[j].local_rank = j + 1 - (num - k);
			}
		}
	}

	printf("%d\n", num);	//输出总考生数
	sort(stu, stu + num, compare);
	int r = 1;
	for (int i = 0; i < num; i++) {
		if (i > 0 && stu[i].score != stu[i - 1].score) {
			r = i + 1;
		}

		printf("%s ", stu[i].id);
		printf("%d %d\n", r, stu[i].location_number, stu[i].local_rank);
	}

	return 0;
}