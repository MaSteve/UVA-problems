#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

ll sieve_size;
bitset<100000020> bs;
vi primes;

inline void sieve(ll upperbound = 100000010) {
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
    while (cin >> n) {
        if (n % 2 == 0) {
            int i = lower_bound(primes.begin(), primes.end(), n/2) - primes.begin();
            i--;
            for (; i >= 0; i--) {
                if (n - primes[i] > 0 && bs[n - primes[i]]) {
                    printf("%d is the sum of %d and %d.\n", n, primes[i], n - primes[i]);
                    break;
                }
            }
            if (i < 0) printf("%d is not the sum of two primes!\n", n);
        } else { // odd + even = odd; odd + odd = even
            if (n > 2 && bs[n-2]) printf("%d is the sum of %d and %d.\n", n, 2, n - 2);
            else printf("%d is not the sum of two primes!\n", n);
        }
    }
    return 0;
}
