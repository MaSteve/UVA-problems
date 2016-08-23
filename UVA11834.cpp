#include <iostream>
using namespace std;

int main() {
    int W, L, R1, R2;
    while (cin >> W >> L >> R1 >> R2 && !(W == 0 && L == 0 && R1 == 0 && R2 == 0)) {
        int x = W - R2 - R1, y = L - R2 - R1;
        bool ok = false;
        if (2*R1 <= W && 2*R1 <= L && 2*R2 <= W && 2*R2 <= L && x >= 0 && y >= 0) {
            ok = (x * x + y * y >= (R2 + R1) * (R2 + R1));
        }
        if (ok) printf("S\n");
        else printf("N\n");
    }
    return 0;
}
