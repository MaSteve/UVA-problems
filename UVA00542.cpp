#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    string teams[16];
    double grid[16][16], prob[16][4];
    for (int i = 0; i < 16; i++) cin >> teams[i];
    for (int i = 0; i < 16; i++)
        for (int j = 0; j < 16; j++)
            cin >> grid[i][j], grid[i][j]/=100;
    for (int i = 0; i < 16; i++) {
        prob[i][0] = grid[i][i%2?i-1:i+1];
    }
    for (int k = 2, l = 1; k <= 8; k *= 2, l++) {
        for (int i = 0; i < 16; i++) {
            double sum = 0;
            for (int j = i - i%k + (i%(k*2)>k-1? -k: k), cont = 0; cont < k; cont++, j++) sum += grid[i][j]*prob[j][l-1];
            prob[i][l] = prob[i][l-1]*(sum);
        }
    }
    for (int i = 0; i < 16; i++) {
        printf("%-10s p=%.2f%%\n", teams[i].c_str(), prob[i][3]*100);
    }
    return 0;
}
