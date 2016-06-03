#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N, code[1002], hint[1002], countc[10], counth[10], cases = 1;
    while (cin >> N && N != 0) {
        printf("Game %d:\n", cases++);
        for (int i = 0; i < N; i++) cin >> code[i];
        do {
            for (int i = 0; i < N; i++) cin >> hint[i];
            for (int i = 0; i < 10; i++) countc[i] = counth[i] = 0;
            if (hint[0] != 0) {
                int sm = 0, wm = 0;
                for (int i = 0; i < N; i++) {
                    if (code[i] == hint[i]) sm++;
                    else {
                        countc[code[i]-1]++;
                        counth[hint[i]-1]++;
                    }
                }
                for (int i = 0; i < 10; i++) {
                    wm += countc[i] > counth[i]? counth[i]: countc[i];
                }
                printf("    (%d,%d)\n", sm, wm);
            }
        } while (hint[0] != 0);
    }
    return 0;
}
