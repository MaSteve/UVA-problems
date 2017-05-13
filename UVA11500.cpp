#include <iostream>
#include <cmath>
using namespace std;

long double ** mat1[7][11], ** mat2;
bool mask[7][11];

inline int trunc(int n) {
    if (n < 0) return 0;
    if (n > 21) return 21;
    return n;
}

void proc(int AT, int D) {
    if (!mask[AT][D]) {
        mask[AT][D] = true;
        long double ** m1 = mat1[AT][D];
        long double ** m2 = mat2;
        for (int i = 0; i < 22; i++) {
            for (int j = 0; j < 22; j++) {
                if (j == 0) m1[i][j] = 1;
                else m1[i][j] = 0;
            }
        }
        for (int it = 0; it < 625; it++) {
            for (int i = 0; i < 22; i++) {
                for (int j = 0; j < 22; j++) {
                    if (i == 0 || j == 0) m2[i][j] = m1[i][j];
                    else m2[i][j] = (AT*m1[trunc(i + D)][trunc(j - D)] + (6-AT)*m1[trunc(i - D)][trunc(j + D)])/6.0;
                }
            }
            long double ** auxi = m1;
            m1 = m2;
            m2 = auxi;
        }
        mat1[AT][D] = m1;
        mat2 = m2;
    }
}

int main() {
    int EV1, EV2, AT, D;
    for (int j = 0; j < 7; j++)
        for (int k = 0; k < 11; k++)
            mat1[j][k] = new long double *[22];
    mat2 = new long double *[22];
    for (int i = 0; i < 22; i++) {
        for (int j = 0; j < 7; j++)
            for (int k = 0; k < 11; k++)
                mat1[j][k][i] = new long double [22];
        mat2[i] = new long double [22];
    }

    for (int j = 0; j < 7; j++)
        for (int k = 0; k < 11; k++)
            proc(j, k);

    while (scanf("%d %d %d %d", &EV1, &EV2, &AT, &D) && !(EV1 == 0 && EV2 == 0 && AT == 0 && D == 0)) {
        long double sol = mat1[AT][D][EV1][EV2];
        printf("%.1Lf\n", sol*100);
    }

    for (int i = 0; i < 22; i++) {
        for (int j = 0; j < 7; j++)
            for (int k = 0; k < 11; k++)
                delete [] mat1[j][k][i];
        delete [] mat2[i];
    }
    for (int j = 0; j < 7; j++)
        for (int k = 0; k < 11; k++)
            delete [] mat1[j][k];
    delete [] mat2;
    return 0;
}
