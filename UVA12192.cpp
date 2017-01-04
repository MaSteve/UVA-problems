#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, M, H[501][501];
    while (cin >> N >> M && !(N == 0 && M == 0)) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> H[i][j];
            }
        }
        int Q, L, U;
        cin >> Q;
        for (int q = 0; q < Q; q++) {
            cin >> L >> U;
            int maxi = 0;
            for (int i = 0; i < N; i++) {
                int j = lower_bound(H[i], H[i] + M, L) - H[i];
                int val = 0;
                for (int k = 0; k < N - i && k < M - j; k++) {
                    if (H[i+k][j+k] <= U) val++;
                    if (val > maxi) maxi = val;
                }
            }
            printf("%d\n", maxi);
        }
        printf("-\n");
    }
    return 0;
}
