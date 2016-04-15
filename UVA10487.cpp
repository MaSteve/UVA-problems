#include <cstdio>
#include <climits>
#include <cmath>
using namespace std;

int main() {
	int set[1000];
	int n, cases = 1;
	while (scanf("%d", &n) && n != 0) {
		for (int i = 0; i < n; i++) scanf("%d", &set[i]);
		int m;
		scanf("%d", &m);
		printf("Case %d:\n", cases++);
		while (m--) {
			int val, dist = INT_MAX, sum = 0;
			scanf("%d", &val);
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					int d = fabs((set[i]+set[j])-val);
					if (d < dist) dist = d, sum = set[i]+set[j];
				}
			}
			printf("Closest sum to %d is %d.\n", val, sum);
		}
	}
	return 0;
}