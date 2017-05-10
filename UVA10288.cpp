#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

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

ii sum (ii & a, ii & b) {
    ll n = a.first*b.second + b.first*a.second;
    ll d = a.second*b.second;
    ll g = gcd(n, d);
    return ii(n / g, d / g);
}

ii proc(int n) {
    ii res = ii(0, 1), auxi = ii(1, 1);
    for (int i = 1; i <= n; i++) {
        auxi.second = i;
        res = sum (res, auxi);
    }
    res.first *= n;
    ll g = gcd(res.first, res.second);
    res.first /= g, res.second /= g;
    return res;
}

int main() {
    int n;
    while (cin >> n) {
        ii res = proc(n);
        if (res.second == 1) printf("%lld\n", res.first);
        else {
            ll n = res.first / res.second, m = res.first % res.second, d = res.second;
            int ln = floor(log10(n)), lm = floor(log10(m)), ld = floor(log10(d));
            for (int i = 0; i <= ln + 1; i++) printf(" ");
            printf("%lld\n", m);
            printf("%lld ", n);
            for (int i = 0; i <= max(lm, ld); i++) printf("-");
            printf("\n");
            for (int i = 0; i <= ln + 1; i++) printf(" ");
            printf("%lld\n", d);
        }
    }
    return 0;
}
