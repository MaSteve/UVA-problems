#include <iostream>
#include <cmath>
using namespace std;

int p, q, r, s, t, u;

long double func(long double x) {
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

bool ss(long double fa, long double fb) {
    return (fa > 0 && fb > 0) || (fa < 0 && fb < 0);
}

bool zero(long double f) {
    return fabs(f) < 1e-9;
}

int main() {
    while (cin >> p >> q >> r >> s >> t >> u) {
        long double a = 0, b = 1;
        while (true) {
            long double mid = (a + b)/2;
            if (fabs(b - a) < 1e-9) {

                printf("%.4Lf\n", mid);
                break;
            }
            long double fa = func(a), fb = func(b), fm = func(mid);
            if (ss(fa, fb)) {
                printf("No solution\n");
                break;
            }
            if (zero(fm)) {
                printf("%.4Lf\n", mid);
                break;
            }
            else if (ss(fa, fm)) a = mid;
            else b = mid;
        }
    }
    return 0;
}
