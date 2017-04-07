#include <iostream>
using namespace std;

typedef long long ll;

int main() {
    ll N;
    while (cin >> N && N != 0) {
        bool ok = true, end = false;
        int solx, soly;
        for (ll x = 2; ok && !end; x++) {
            ll px = x*x*x;
            for (ll y = x - 1; y > 0 && ok && !end; y--) {
                ll py = y*y*y;
                if (px - py > N) {
                    if (y == x - 1) ok = false;
                    break;
                }
                if (px - py == N) solx = x, soly = y, end = true;
            }
        }
        if (ok) printf("%d %d\n", solx, soly);
        else printf("No solution\n");
    }
    return 0;
}
