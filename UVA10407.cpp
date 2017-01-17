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
    ll n, m, g;
    while (cin >> n && n != 0) {
        cin >> m;
        g = n - m;
        n = m;
        while (cin >> m && m != 0) {
            g = gcd(g, n - m);
            n = m;
        }
        if (g < 0) g = -g;
        printf("%lld\n", g);
    }
    return 0;
}
