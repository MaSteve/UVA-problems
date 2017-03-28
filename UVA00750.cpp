#include <iostream>
using namespace std;

int sol[8];
int mask[8][8];

int cont;

void func(int col) {
    if (col == 8) {
        printf("%2d     ", cont++);
        for (int i = 0; i < 8; i++)
            printf(" %d", sol[i]);
        printf("\n");
        return;
    }
    if (sol[col] != 0) {
        func(col + 1);
        return;
    }
    for (int i = 0; i < 8; i++) {
        if (!mask[i][col]) {
            for (int j = 0; j < 8; j++) {
                mask[j][col]++;
                mask[i][j]++;
                if (i-col+j < 8 && i-col+j >= 0) mask[i-col+j][j]++;
                if (col+i-j < 8 && col+i-j >= 0) mask[col+i-j][j]++;
            }
            sol[col] = i + 1;
            func(col + 1);
            for (int j = 0; j < 8; j++) {
                mask[j][col]--;
                mask[i][j]--;
                if (i-col+j < 8 && i-col+j >= 0) mask[i-col+j][j]--;
                if (col+i-j < 8 && col+i-j >= 0) mask[col+i-j][j]--;
            }
        }
    }
    sol[col] = 0;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int row, col;
        cin >> row >> col;
        row--, col--;
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                mask[i][j] = 0;
        for (int j = 0; j < 8; j++) {
            sol[j] = 0;
            mask[row][j]++;
            mask[j][col]++;
            if (row-col+j < 8 && row-col+j >= 0) mask[row-col+j][j]++;
            if (col+row-j < 8 && col+row-j >= 0) mask[col+row-j][j]++;
        }
        printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");
        sol[col] = row + 1;
        cont = 1;
        func(0);
        if (T) printf("\n");
    }
    return 0;
}
