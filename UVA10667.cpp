#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

pair<int, int> grid[100][100];
pair<int, int> bound[100][100];
int s;
int maxi;

void proc(){
	int ac = 1;
	for (int x = 0; x < s; x++) {
		if (grid[x][0].first == -1) {
			grid[x][0].first = ac;
			grid[x][0].second = 1;
			bound[x][0].first = ac;
			bound[x][0].second = 1;
			if (ac > maxi) maxi = ac;
			ac++;
		} else ac = 1;
	}
	ac = 1;
	for (int y = 0; y < s; y++) {
		if (grid[0][y].first == -1 || grid[0][y].first == 1) {
			grid[0][y].first = 1;
			grid[0][y].second = ac;
			bound[0][y].first = 1;
			bound[0][y].second = ac;
			if (ac > maxi) maxi = ac;
			ac++;
		} else ac = 1;
	}
	for (int x = 1; x < s; x++) {
		for (int y = 1; y < s; y++) {
			if (grid[x][y].first == -1) {
				bound[x][y].first = bound[x-1][y].first + 1;
				bound[x][y].second = bound[x][y-1].second + 1;
				if (grid[x-1][y].first == 0) {
					grid[x][y].first = 1;
					grid[x][y].second = bound[x][y].second;
				} else if (grid[x][y-1].first == 0) {
					grid[x][y].first = bound[x][y].first;
					grid[x][y].second = 1;
				} else {
					int x1 = grid[x-1][y].first + 1, y1 = min(grid[x-1][y].second, bound[x][y].second), x2 = min(grid[x][y-1].first, bound[x][y].first), y2 = grid[x][y-1].second + 1;
					if ((x1*y1) > (x2*y2)) {
						grid[x][y].first = x1;
						grid[x][y].second = y1;
					} else {
						grid[x][y].first = x2;
						grid[x][y].second = y2;
					}
				}
				if (grid[x][y].first * grid[x][y].second > maxi) maxi = grid[x][y].first * grid[x][y].second;
			}
		}
	}
}

int main(){
	int cases;
	scanf("%d\n", &cases);
	for (int i = 0; i < cases; i++) {
		int blocks;
		maxi = 0;
		scanf("%d\n%d", &s, &blocks);
		for (int x = 0; x < s; x++) {
			for (int y = 0; y < s; y++) {
				grid[x][y].first = -1;
				grid[x][y].second = -1;
			}
		}
		for (int j = 0; j < blocks; j++) {
			int r1, r2, c1, c2;
			scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
			for (int x = r1-1; x <= r2-1; x++) {
				for (int y = c1-1; y <= c2-1; y++) {
					grid[x][y].first = 0;
					grid[x][y].second = 0;
					bound[x][y].first = 0;
					bound[x][y].second = 0;
				}
			}
		}
		proc();
		printf("%d\n", maxi);
	}
	return 0;
}