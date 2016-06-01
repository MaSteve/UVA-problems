#include <iostream>
using namespace std;

char images[25][25], mask[25][25];
int N;

int proc(int i, int j) {
    if (i < N && j < N && i >= 0 && j >= 0 && !mask[i][j]) {
        mask[i][j] = 1;
        if (images[i][j] == '1') {
            for (int m = -1; m <= 1; m++)
                for (int n = -1; n <= 1; n++)
                    proc(i+m, j+n);
        }
        return images[i][j] - '0';
    }
    return 0;
}

int main() {
    int cases = 1, count;
    while (cin >> N) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> images[i][j], mask[i][j] = 0;
        count = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                count += proc(i, j);
        printf("Image number %d contains %d war eagles.\n", cases++, count);
    }
    return 0;
}
