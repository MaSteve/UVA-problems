#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

ll sieve_size;
bitset<10000010> bs;
vi primes;

inline void sieve(ll upperbound = 10000000) {
    sieve_size=upperbound+1;
    bs.set(); bs[0]=bs[1]=0;
    for (ll i=2; i<=sieve_size; i++) if(bs[i]) {
        for (ll j=i*i; j<=sieve_size; j+=i) bs[j] = 0;
        primes.push_back((int)i);
    }
}

inline ii check(int n) {
    for (int i = 0; i < primes.size(); i++) {
        if (n - primes[i] < primes[i]) break;
        if (bs[n - primes[i]]) return ii(primes[i], n - primes[i]);
    }
    return ii(0, 0);
}

int main() {
    sieve();
    int n;
    while (cin >> n) {
        bool ok = false;
        for (int i = 4; !ok; i++) {
            int j = n - i;
            if (j < i) break;
            ii p1 = check(i), p2 = check(j);
            if (p1.first != 0 && p2.first != 0) {
                ok = true;
                printf("%d %d %d %d\n", p1.first, p1.second, p2.first, p2.second);
            }
        }
        if (!ok) printf("Impossible.\n");
    }
    return 0;
}
