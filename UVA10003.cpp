#include <cstdio>
using namespace std;

int grid[53][53];
int l, n;
int cuts[53];

int mincost(int i, int j) {
	if (grid[i][j] == -1) {
		int min = 900000;
		bool cut = false;
		for (int m = i + 1; m < j; m++) {
			cut = true;
			int val = mincost(i, m) + mincost(m, j);
			if (val < min) min = val;
		}
		grid[i][j] = cut? cuts[j] - cuts[i] + min: 0;
	}
	return grid[i][j];
}

int main() {
	while (scanf("%d", &l) != EOF && l != 0) {
		scanf("%d", &n);
		cuts[0] = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &cuts[i]);
		}
		cuts[n+1] = l;
		for (int i = 0; i <= n + 1; i++) {
			for (int j = 0; j <= n + 1; j++) {
				grid[i][j] = -1;
			}
		}
		int min = mincost(0, n + 1);
		printf("The minimum cutting is %d.\n", min);
	}
	return 0;
}