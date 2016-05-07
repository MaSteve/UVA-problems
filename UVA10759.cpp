#include <iostream>
#include <cmath>
using namespace std;

int main() {
    unsigned long long grid[25][150];
    unsigned long long div[25][150];
    for (int i = 0; i < 25; i++)
        for (int j = 0; j < 150; j++)
            grid[i][j] = 0, div[i][j] = 1;
    grid[1][1] = grid[1][2] = grid[1][3] = grid[1][4] = grid[1][5] = grid[1][6] = 1;
    for (int i = 1, sum = 6; i < 24; i++, sum += 6) {
        for (int j = 0; j < 150 && j <= sum; j++) {
            for (int l = 1; l <= 6; l++) {
                grid[i+1][j+l] += grid[i][j];
            }
        }
    }

    for (int i = 1, sum = 6; i < 25; i++, sum += 6) {
        for (int j = sum; j >= 0; j--) {
            int div2 = i, div3 = i;
            if (j != 0) grid[i][j-1] += grid[i][j];
            while (grid[i][j] != 0 && div2 > 0 && grid[i][j]%2 == 0) grid[i][j] /= 2, div2--;
            while (grid[i][j] != 0 && div2 > 0 && grid[i][j]%3 == 0) grid[i][j] /= 3, div3--;
            div[i][j] = pow(2, div2)*pow(3,div3);
            if (div[i][j] == grid[i][j]) div[i][j] = grid[i][j] = 1;
        }
    }

    int n, x;
    while (cin >> n >> x && !(n == 0 && x == 0)) {
        cout << grid[n][x];
        if (grid[n][x] != 0 && div[n][x] != 1) cout << "/" << div[n][x];
        cout << endl;
    }
    return 0;
}
