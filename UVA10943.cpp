#include <iostream>
using namespace std;

int main() {
	int grid[101][101];
	for (int i = 0; i < 101; i++) grid[i][0] = grid[0][i] = 1;
	for (int i = 1; i < 101; i++)
		for (int j = 1; j < 101; j++)
			grid[i][j] = (grid[i-1][j] + grid[i][j-1]) % 1000000;
	int N, K;
	while (cin >> N >> K && !(N == 0 && K == 0)) {
		cout << grid[K-1][N] << endl;
	}
	return 0;
}