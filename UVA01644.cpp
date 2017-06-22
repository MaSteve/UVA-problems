#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll sieve_size;
bitset<100000020> bs;
vi primes;

inline void sieve(ll upperbound = 1300000) {
    sieve_size=upperbound+1;
    bs.set(); bs[0]=bs[1]=0;
    for (ll i=2; i<=sieve_size; i++) if(bs[i]) {
        for (ll j=i*i; j<=sieve_size; j+=i) bs[j] = 0;
        primes.push_back((int)i);
    }
}

int main() {
    sieve();
    int n;
    while (cin >> n && n != 0) {
        if (bs[n]) printf("0\n");
        else {
            int i = lower_bound(primes.begin(), primes.end(), n) - primes.begin();
            printf("%d\n", primes[i] - primes[i - 1]);
        }
    }
    return 0;
}
