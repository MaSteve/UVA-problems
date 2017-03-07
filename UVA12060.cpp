#include <iostream>
#include <utility>
#include <cmath>
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
    int n, c = 1;
    while (cin >> n && n != 0) {
        int acum = 0;
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            acum += val;
        }
        bool sign = acum < 0;
        if (sign) acum = - acum;
        int g = gcd(acum, n);
        n /= g;
        acum /= g;
        int a = acum/n, b = acum%n;
        int la = ceil(log10(a + 0.5)), lb = ceil(log10(b + 0.5)), ln = ceil(log10(n + 0.5));
        printf("Case %d:\n", c++);
        if (n == 1) {
            if (sign) printf("- ");
            printf("%d\n", a);
        } else {
            if (sign) printf("  ");
            for (int i = 0; i < la + ln - lb; i++) printf(" ");
            printf("%d\n", b);
            if (sign) printf("- ");
            if (a > 0) printf("%d", a);
            for (int i = 0; i < ln; i++) printf("-");
            printf("\n");
            if (sign) printf("  ");
            for (int i = 0; i < la; i++) printf(" ");
            printf("%d\n", n);
        }
    }
    return 0;
}
