#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;

unordered_map<int, unordered_map<int, long double> > dp;
int pn, pd, n;

long double proc(int w, int l) {
    if (w + l > n) return 0;
    if (w + l <= n && w * pd > pn * (w+l)) return 1;
    if (!dp.count(w) || !dp[w].count(l)) {
        dp[w][l] = (pn*proc(w+1, l) + (pd-pn)*proc(w, l+1)) / ((long double) pd);
    }
    return dp[w][l];
}

int main() {
    int N;
    cin >> N;
    for (int c = 1; c <= N; c++) {
        scanf("%d/%d %d", &pn, &pd, &n);
        dp.clear();
        long double pf = proc(0, 0);
        if (ceil(1/(1-pf)) - (1/(1-pf)) < 1e-9) printf("Case #%d: %.0Lf\n", c, ceil(1/(1-pf)));
        else printf("Case #%d: %.0Lf\n", c, floor(1/(1-pf)));
    }
    return 0;
}
