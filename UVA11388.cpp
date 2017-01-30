#include <iostream>
using namespace std;

typedef long long ll;

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

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll G, L, P;
        cin >> G >> L;
        P = G * L;
        ll a = G, b = L, i = 1;
        while (a <= b) {
            ll val = gcd(a, b);
            if (val == G && (i * b) == L) break;
            i++;
            a = i * G;
            b = P / a;
        }
        if (a > b) printf("-1\n");
        else printf("%lld %lld\n", a, b);
    }
    return 0;
}
