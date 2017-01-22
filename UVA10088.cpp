#include <iostream>
#include <complex>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef complex<ll> point, vect;
typedef vector<point> polygon;
typedef polygon::iterator polIter;
const ld inf = 1e9; const ld eps = 1e-9; const ld pi = acos(-1.0);

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

vect toVec(point a, point b) {
    return vect(b.real() - a.real(), b.imag() - a.imag());
}

ll area(polygon &p) {
    ll result = 0;
    for (int i = 0; i < p.size(); i++)
        result += imag(conj(p[i])*p[(i+1)%p.size()]);
    return abs(result) / 2;
}

int main() {
    int N;
    while (cin >> N && N != 0) {
        polygon pol;
        for (int i = 0; i < N; i++) {
            ll x, y;
            cin >> x >> y;
            pol.push_back(point(x, y));
        }
        ld a = area(pol);
        ll b = N;
        vect v = toVec(pol[N - 1], pol[0]);
        b += abs(gcd(v.real(), v.imag())) - 1;
        for (int i = 1; i < N; i++) {
            v = toVec(pol[i], pol[i-1]);
            b += abs(gcd(v.real(), v.imag())) - 1;
        }
        ll i = a + 1 - (b/2);
        printf("%lld\n", i);
    }
    return 0;
}
