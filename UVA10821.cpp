#include <iostream>
#include <cmath>
using namespace std;

void proc(int N, int H, int offset) {
    if (H != 0 && offset <= N) {
        int k = H-1;
        int next = N - ((1 << k) - 1);
        if (next < offset) next = offset;
        printf(" %d", next);
        proc(next - 1, H-1, offset);
        proc(N, H-1, next + 1);
    }
}

int main() {
    int N, H, c = 1;
    while (cin >> N >> H && !(N == 0 && H == 0)) {
        printf("Case %d:", c);
        if ((1 << H) - 1 < N) printf(" Impossible.\n");
        else {
            if (H > N) H = N;
            proc(N, H, 1);
            printf("\n");
        }
        c++;
    }
    return 0;
}
