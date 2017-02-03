#include <iostream>
using namespace std;

int mat[5][5];
int sol[9];

void proc(int n, int p) {
    sol[p] = n + 1;
    if (p == 8) {
        for (int i = 0; i < 9; i++) printf("%d", sol[i]);
        printf("\n");
    } else {
        for (int i = 0; i < 5; i++) {
            if (mat[n][i]) {
                mat[n][i] = mat[i][n] = 0;
                proc(i, p+1);
                mat[n][i] = mat[i][n] = 1;
            }
        }
    }
}

int main() {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            mat[i][j] = 0;
    mat[0][1] = mat[1][0] = mat[0][2] = mat[2][0] =
    mat[0][4] = mat[4][0] = mat[1][2] = mat[2][1] =
    mat[1][4] = mat[4][1] = mat[2][3] = mat[3][2] =
    mat[2][4] = mat[4][2] = mat[3][4] = mat[4][3] = 1;
    proc(0, 0);
    return 0;
}
