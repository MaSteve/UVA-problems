#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T;
    int v[10];
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        long long acum = 1, val = 2, vlen = 1;
        for (; acum < n; val++) {
            vlen += floor(log10(val)) + 1;
            acum += vlen;
        }
        n -= acum - vlen;
        int i = 1;
        acum = 0, vlen = 0;
        for (; acum < n; i++) {
            vlen = floor(log10(i)) + 1;
            acum += vlen;
        }
        i--, acum -= vlen;
        int j = 0;
        while (i) {
            v[j] = i % 10;
            i /= 10;
            j++;
        }
        int res = -1;
        while (acum < n) {
            j--;
            res = v[j];
            acum++;
        }
        printf("%d\n", res);
    }
    return 0;
}
