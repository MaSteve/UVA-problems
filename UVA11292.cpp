#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int heads[20001];
	int knights[20001];
	int n, m;
	while (scanf("%d %d", &n, &m) && !(n == 0  && m == 0)) {
		int cost = 0;
		for (int i = 0; i < n; i++) scanf("%d", &heads[i]);
		for (int i = 0; i < m; i++) scanf("%d", &knights[i]);
		sort(heads, heads+n);
		sort(knights, knights+m);
		int i = 0, j = 0;
		bool stop = false;
		while (i < n && j < m) {
			if (heads[i] <= knights[j]) {
				cost += knights[j];
				i++;
			}
			j++;
			if (n - i > m - j) stop = true;
		}
		if (stop) printf("Loowater is doomed!\n");
		else printf("%d\n", cost);
	}
	return 0;
}