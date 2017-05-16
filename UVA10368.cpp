#include <iostream>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int gcd(ll n, ll m) {
    ll auxi;
    if (m > n) {
        auxi = n;
        n = m, m = auxi;
    }
    if (n % m == 0) return 0;
    int val = gcd(m, n%m);
    if (n / m == 1) {
        val = 1 - val;
    } else val = 0;
    return val;
}

int main() {
    int n, m;
    while (cin >> n >> m && !(n == 0 && m == 0)) {
        int val = gcd(n, m);
        if (val) printf("Ollie wins\n");
        else printf("Stan wins\n");
    }
    return 0;
}
