#include <iostream>
#include <cmath>
using namespace std;

int tax(double k) {
    double t = 0;
    k -= 180000;
    if (k > 0) t += (k <= 300000? k: 300000)*0.1, k -= 300000;
    if (k > 0) t += (k <= 400000? k: 400000)*0.15, k -= 400000;
    if (k > 0) t += (k <= 300000? k: 300000)*0.20, k -= 300000;
    if (k > 0) t += k*0.25;
    return ceil(t);
}

int main() {
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        double k;
        cin >> k;
        int t = tax(k);
        if (t != 0 && t < 2000) t = 2000;
        printf("Case %d: %d\n", c, t);
    }
    return 0;
}
