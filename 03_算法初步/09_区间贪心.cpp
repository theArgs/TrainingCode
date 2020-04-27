#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 110;

struct Inteval {
	int x, y;
}I[maxn];

bool compare(Inteval a, Inteval b) {
	if (a.x != b.x) return a.x > b.x;	//按照左端点从大到小排序
	else return a.y < b.y;	//左端点相同按照右端点从小到大排序
}

int main() {

	int n;
	while (scanf("%d", &n), n != 0) {
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &I[i].x, &I[i].y);
		}
		sort(I, I + n, compare);
		// ans记录不相交区间个数, lastX记录上一个被选中区间的左端点
		int ans = 1, lastX = I[0].x;
		for (int i = 1; i < n; i++) {
			if (I[i].y <= lastX) {	//如果该区间右端点在lastX左边
				lastX = I[i].x;	//以I[i]作为新选中的区间
				ans++;	//不相交区间个数加1
			}
		}

		printf("%d\n", ans);
	}
	return 0;
}

//总是先选择右端点最小的区间的策略也可行