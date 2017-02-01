#include <iostream>
#include <bitset>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <set>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll sieve_size;
bitset<100000001> bs;
set<int> primes;


inline void sieve(ll upperbound = 1000002) {
    sieve_size=upperbound+1;
    bs.set(); bs[0]=bs[1]=0;
    for (ll i=2; i<=sieve_size; i++) if(bs[i]) {
        for (ll j=i*i; j<=sieve_size; j+=i) bs[j] = 0;
        primes.insert((int)i);
    }
}

int main() {
    sieve();
    int n;
    while (cin >> n && n != 0) {
        int b;
        for (auto it = primes.begin(); it != primes.end(); ++it) {
            b = n - (*it);
            if (primes.count(b)) break;
        }
        printf("%d = %d + %d\n", n, n - b, b);
    }
    return 0;
}
