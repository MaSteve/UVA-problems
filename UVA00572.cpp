#include <cstdio>
using namespace std;

bool grid[100][100];
int m, n;

void empty(int x, int y) {
	if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y]) {
		grid[x][y] = false;
		empty(x-1, y-1);
		empty(x-1, y);
		empty(x-1, y+1);
		empty(x, y-1);
		empty(x, y+1);
		empty(x+1, y-1);
		empty(x+1, y);
		empty(x+1, y+1);
	}
}

int main() {
	while (scanf("%d %d", &m, &n) && m != 0) {
		for (int i = 0; i < m; i++) {
			char c;
			scanf("%c", &c);
			for (int j = 0; j < n; j++) {
				scanf("%c", &c);
				grid[i][j] = c == '@';
			}
		}
		int cont = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j]) {
					empty(i, j);
					cont ++;
				}
			}
		}
		printf("%d\n", cont);
	}
	return 0;
}