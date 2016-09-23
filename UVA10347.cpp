#include <iostream>
#include <cmath>
using namespace std;

const double eps=1e-9;

int main() {
    double ma, mb, mc, v;
    while (cin >> ma >> mb >> mc) {
        bool invalid = (ma <= 0 || mb <= 0 || mc <= 0);
        if (!invalid) {
            v = (ma + mb + mc)*(-ma + mb + mc)*(ma - mb + mc)*(ma + mb - mc);
            invalid = (v <= 0);
        }
        if (invalid) printf("-1.000\n");
        else printf("%.3lf\n", (sqrt(v))/3);
    }
    return 0;
}
