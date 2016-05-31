#include <iostream>
using namespace std;

int grid[8][8];
int mask[8][8];

int maxi;

void func(int sum, int row) {
    if (row == 8) {
        if (sum > maxi) maxi = sum;
        return;
    }
    for (int i = 0; i < 8; i++) {
        if (!mask[row][i]) {
            for (int j = 0; j < 8; j++) {
                mask[row][j]++;
                mask[j][i]++;
                if (i-row+j < 8 && i-row+j >= 0) mask[j][i-row+j]++;
                if (i+row-j < 8 && i+row-j >= 0) mask[j][i+row-j]++;
            }
            func(sum + grid[row][i], row + 1);
            for (int j = 0; j < 8; j++) {
                mask[row][j]--;
                mask[j][i]--;
                if (i-row+j < 8 && i-row+j >= 0) mask[j][i-row+j]--;
                if (i+row-j < 8 && i+row-j >= 0) mask[j][i+row-j]--;
            }
        }
    }
}

int main() {
    int boards;
    cin >> boards;
    while (boards--) {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                cin >> grid[i][j], mask[i][j] = 0;
        maxi = 0;
        func(0, 0);
        printf("%5d\n", maxi);
    }
    return 0;
}
