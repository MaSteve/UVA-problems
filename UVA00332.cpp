#include <iostream>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

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
    int j, c = 1;
    while (cin >> j && j != -1) {
        string s;
        cin >> s;
        int k = s.length() - j - 2;
        ll a = 0, b = 0, p1 = 1, p2 = 1;
        for (int i = 2; i < s.length(); i++) {
            a *= 10;
            a += s[i] - '0';
            p1 *= 10;
            if (i - 1 == k) {
                b = a;
                p2 = p1;
            }
        }
        if (j != 0) a -= b, p1 -= p2;
        ll g = gcd(a, p1);
        a /= g, p1 /= g;
        printf("Case %d: %lld/%lld\n", c++, a, p1);
    }
    return 0;
}
