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
    int n, m;
    int c[10001];
    while (cin >> n >> m && !(n == 0 && m == 0)) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> c[i];
            sum += c[i];
        }
        for (int i = 0; i < n; i++) {
            int g = gcd(c[i], sum);
            printf("%d / %d\n", c[i] / g, sum / g);
        }
    }
    return 0;
}
