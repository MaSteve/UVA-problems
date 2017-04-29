#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

ll sieve_size;
bitset<100000001> bs;
vi primes;

inline void sieve(ll upperbound = 50000) {
    sieve_size=upperbound+1;
    bs.set(); bs[0]=bs[1]=0;
    for (ll i=2; i<=sieve_size; i++) if(bs[i]) {
        for (ll j=i*i; j<=sieve_size; j+=i) bs[j] = 0;
        primes.push_back((int)i);
    }
}

inline void primeFactors(ll n, vii & factors) {
    int c;
    ll idx=0, p=primes[0];
    while (n!=1 && (p*p<=n)) {
        c=0; while(n%p==0) c++, n/=p;
        if(c!=0) factors.push_back(ii(p,c));
        p=primes[++idx];
    }
    if (n!=1) factors.push_back(ii(n,1));
}

int main() {
    sieve();
    long long n, m;
    vii factors;
    while (cin >> n >> m) {
        bool ok = true;
        if (n < m) {
            factors.clear();
            primeFactors(m, factors);
            long long k = 2;
            for (int i = 0; i < factors.size(); i++) {
                long long mult = 1;
                for (k = mult * factors[i].first; factors[i].second > 0 && k <= n; k = mult * factors[i].first) {
                    while (k % factors[i].first == 0 && k > 0 && factors[i].second > 0) {
                        k /= factors[i].first;
                        factors[i].second--;
                    }
                    mult++;
                }
                if (factors[i].second > 0) break;
            }
            ok = true;
            for (int i = 0; i < factors.size() && ok; i++) ok = factors[i].second == 0;
        }
        if (ok) printf("%lld divides %lld!\n", m, n);
        else printf("%lld does not divide %lld!\n", m, n);
    }
    return 0;
}
