#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        double res = 0;
        for (int i = 1; i < n; i++) {
            double d1 = 10000.0/n, d2 = 10000.0/(n+m);
            double cur = i*d1;
            double f = floor(cur/d2)*d2, c = ceil(cur/d2)*d2;
            if (cur - f < c - cur) res += cur - f;
            else res += c - cur;
        }
        printf("%.4lf\n", res);
    }
    return 0;
}
