#include <iostream>
using namespace std;

int main() {
	long long grid[51][51][51];
	for (int n = 1; n < 51; n++) {
		for (int k = 1; k < 51; k++) {
			for (int m = 1; m < 51; m++) {
				if (n < k) grid[n][k][m] = 0;
				else if (n < m) grid[n][k][m] = grid[n][k][n];
				else if (k == 1) {
					if (n <= m) grid[n][k][m] = 1;
					else grid[n][k][m] = 0;
				}
				else if (n == k) grid[n][k][m] = grid[n-1][k-1][m];
				else {
					grid[n][k][m] = 0;
					for (int i = 1; i <= m && i < n; i++) {
						grid[n][k][m] += grid[n-i][k-1][m];
					}
				}
			}
		}
	}
	int N, K, M;
	while (cin >> N >> K >> M) {
		cout << grid[N][K][M] << endl;
	}
	return 0;
}