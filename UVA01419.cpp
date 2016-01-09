#include <cstdio>
using namespace std;

int main() {
	char grid[100][100];
	int tops[30];
	int x, y;
	while (scanf("%d %d", &x, &y) && !(x == 0 && y == 0)) {
		for (int i = 0; i < 30; i++) tops[i] = 0;
		for (int i = 0; i < x; i++) scanf("%s", grid[i]);
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				if (grid[i][j] != '.' && tops[grid[i][j] - 'A'] == 0) {
					char c = grid[i][j];
					if (i + 1 < x && grid[i+1][j] == c){
						tops[c - 'A'] = 1;
						int l = j;
						for (; l < y && grid[i][l] == c; l++);
						if (grid[i+1][l-1] == c && l > j + 1) {
							int k = i + 1;
							bool stop = false;
							for (; k < x && grid[k][j] == c && !stop; k++) {
								for (int m = j + 1; m < l; m++) {
									if (grid[k][m] != c && grid[k][m] != '.') {
										stop = true;
										break;
									}
								}
							}
							if (stop || grid[k - 1][j + 1] != c) tops[c - 'A'] = 2;
						} else tops[c - 'A'] = 2;
					} else tops[c - 'A'] = 2;
				}
			}
		}
		for (int i = 0; i < 30; i++) if (tops[i] == 1) printf("%c", i + 'A');
		printf("\n");
	}
	return 0;
}