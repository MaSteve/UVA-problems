#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll sieve_size;
bitset<100000001> bs;
vi primes;

inline void sieve(ll upperbound = 1010) {
    sieve_size=upperbound+1;
    bs.set(); bs[0]=bs[1]=0;
    for (ll i=2; i<=sieve_size; i++) if(bs[i]) {
        for (ll j=i*i; j<=sieve_size; j+=i) bs[j] = 0;
        primes.push_back((int)i);
    }
}

int main() {
    primes.push_back(1);
    sieve();
    int N, C;
    while (cin >> N >> C) {
        int ub = upper_bound(primes.begin(), primes.end(), N) - primes.begin();
        int pos = ub/2;
        int i = pos - C + (ub%2? 1: 0);
        int l = pos + C;
        i = max(i, 0);
        l = min(l, ub);
        printf("%d %d:", N, C);
        for (; i < l; i++) printf(" %d", primes[i]);
        printf("\n\n");
    }
    return 0;
}
