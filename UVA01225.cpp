#include <cstdio>
using namespace std;

int main() {
	int grid[10002][10];
	for (int i = 0; i < 10; i++) {
		grid[0][i] = 0;
	}
	for (int i = 1; i < 10002; i++) {
		for (int j = 0; j < 10; j++) {
			grid[i][j] = grid[i-1][j] + (i%10 == j? 1: 0) + ((i/10)%10 == j && i >= 10? 1: 0) + ((i/100)%10 == j && i >= 100? 1: 0) + ((i/1000)%10 == j && i >= 1000? 1: 0) + ((i/10000)%10 == j && i >= 10000? 1: 0);
		}
	}
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		for (int j = 0; j < 10; j++) {
			printf("%d", grid[n][j]);
			if (j != 9) printf(" ");
		}
		printf("\n");
	}
	return 0;
}