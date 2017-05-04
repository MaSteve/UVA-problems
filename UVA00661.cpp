#include <iostream>
using namespace std;

int main() {
    int n, m, c, cs = 1;
    int amperes[21];
    int on[21];
    while (cin >> n >> m >> c && !(n == 0 && m == 0 && c == 0)) {
        int current = 0, maxi = 0;
        bool ok = true;
        for (int i = 0; i < n; i++) cin >> amperes[i], on[i] = 0;
        for (int i = 0; i < m; i++) {
            int sw;
            cin >> sw;
            sw--;
            if (!on[sw]) current += amperes[sw], maxi = max(maxi, current);
            else current -= amperes[sw];
            on[sw] = !on[sw];
        }
        if (maxi > c) printf("Sequence %d\nFuse was blown.\n\n", cs++);
        else printf("Sequence %d\nFuse was not blown.\nMaximal power consumption was %d amperes.\n\n", cs++, maxi);
    }
    return 0;
}
