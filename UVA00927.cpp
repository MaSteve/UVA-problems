#include <iostream>
#include <cmath>
using namespace std;

inline int proc(int n) {
    return ceil((sqrt(1 + 8*n) - 1) / 2);
}

int main() {
    int pol[25];
    int C;
    cin >> C;
    while (C--) {
        int deg;
        cin >> deg;
        for (int i = 0; i <= deg; i++) {
            cin >> pol[i];
        }
        int d, k;
        cin >> d >> k;
        k--;
        int n = proc(k/d + 1);
        long long val = 0;
        for (int i = deg; i >= 0; i--) {
            val *= n;
            val += pol[i];
        }
        printf("%lld\n", val);
    }
    return 0;
}
