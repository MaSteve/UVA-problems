#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll sieve_size;
bitset<100010060> bs;
vi eulerPrimes;

inline void sieve(ll upperbound = 100010050) {
    sieve_size=upperbound+1;
    bs.set(); bs[0]=bs[1]=0;
    for (ll i=2; i<=sieve_size; i++) if(bs[i]) {
        for (ll j=i*i; j<=sieve_size; j+=i) bs[j] = 0;
    }
}

int main() {
    sieve();
    for (int i = 0; i <= 10000; i++) {
        int n = i*i + i + 41;
        if (bs[n]) eulerPrimes.push_back(n);
    }
    int a, b;
    while (scanf("%d %d", &a, &b) == 2) {
        int val = upper_bound(eulerPrimes.begin(), eulerPrimes.end(), b*b + b + 41) - lower_bound(eulerPrimes.begin(), eulerPrimes.end(), a*a + a + 41);
        double ret = round(double(val * 10000) / (b - a + 1)) / 100;
        printf("%.2lf\n", ret);
    }
    return 0;
}
