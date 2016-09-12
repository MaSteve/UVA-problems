#include <iostream>
using namespace std;

string grid[100];
bool mask[100][100];
int N;

int proc() {
    int ships = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!mask[i][j]) {
                if (grid[i][j] == 'x') {
                    ships++;
                    mask[i][j] = true;
                    for (int k = j+1; k < N && grid[i][k] != '.'; k++) mask[i][k] = true;
                    for (int k = j-1; k >= 0 && grid[i][k] != '.'; k--) mask[i][k] = true;
                    for (int k = i+1; k < N && grid[k][j] != '.'; k++) mask[k][j] = true;
                    for (int k = i-1; k >= 0 && grid[k][j] != '.'; k--) mask[k][j] = true;
                }
            }
        }
    }
    return ships;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> grid[i];
            for (int j = 0; j < N; j++) mask[i][j] = false;
        }
        printf("Case %d: %d\n", i, proc());
    }
    return 0;
}
