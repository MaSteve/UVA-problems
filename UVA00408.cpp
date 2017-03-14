#include <iostream>
#include <set>
#include <utility>
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
    ll step, mod;
    while (cin >> step >> mod) {
        printf("%10lld%10lld    ", step, mod);
        step %= mod;
        if (gcd(step, mod) == 1) {
            printf("Good Choice\n\n");
        } else {
            printf("Bad Choice\n\n");
        }
    }
    return 0;
}
