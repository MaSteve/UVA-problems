#include <iostream>
#include <utility>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

int n[10010], k[100010];
int m;

ll gcd(ll n, ll m) {
    ll auxi;
    if (m > n) {
        auxi = n;
        n = m, m = auxi;
    }
    while (m != 0) {
        auxi = n;
        n = m, m = auxi%m;
    }
    return n;
}

ii simp(ll n, ll m) {
    if (n == 0) return ii(0, 1);
    ll g = gcd(n, m);
    return ii(n/g, m/g);
}

ii sum(ii a, ii b) {
    return simp(a.first*b.second + b.first*a.second, a.second*b.second);
}

ii prob(int i) {
    return ii(k[i], n[i]);
}

ii proc(int i) {
    if (i >= m) return ii(0,1);
    else {
        ii p = prob(i);
        return sum(p, proc(i+1));
    }
}

int main() {
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> n[i] >> k[i];
        }
        ii res = proc(0);
        printf("Case %d: %lld/%lld\n", c, res.first, res.second);
    }
    return 0;
}
