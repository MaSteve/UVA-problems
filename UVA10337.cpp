#include <iostream>
using namespace std;

int grid[10][1001], X;
int cost[10][1001];

void proc(int x, int h) {
	if (cost[h][x] != -1) return;
	cost[h][x] = 90000;
	if (x == X - 1) {
		cost[0][x] = 30 - grid[0][x];
		cost[1][x] = 20 - grid[1][x];
		return;
	}
	if (h < 9 &&  h < X-x-1) {
		proc(x + 1, h + 1);
		cost[h][x] = 60 - grid[h][x] + cost[h+1][x+1];
	}
	int price;
	if (h <= X-x-1) {
		proc(x + 1, h);
		price = 30 - grid[h][x] + cost[h][x+1];
		cost[h][x] = min(price, cost[h][x]);
	}
	if (h > 0) {
		proc(x + 1, h - 1);
		price = 20 - grid[h][x] + cost[h-1][x+1];
		cost[h][x] = min(price, cost[h][x]);
	}
}

int main() {
	int N;
	cin >> N;
	while (N--) {
		cin >> X;
		X /= 100;
		for (int i = 9; i >= 0; i--) {
			for (int j = 0; j < X; j++) {
				cin >> grid[i][j];
				cost[i][j] = -1;
			}
		}
		proc(0, 0);
		cout << cost[0][0] << endl << endl;
	}
	return 0;
}