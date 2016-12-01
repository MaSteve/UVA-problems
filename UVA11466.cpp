#include <iostream>
#include <bitset>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> llll;
typedef vector<llll> vll;

ll sieve_size;
bitset<100000001> bs;
vi primes;

inline void sieve() {
    sieve_size=100000001;
    bs.set(); bs[0]=bs[1]=0;
    for (ll i=2; i<=sieve_size; i++) if(bs[i]) {
        for (ll j=i*i; j<=sieve_size; j+=i) bs[j] = 0;
        primes.push_back((int)i);
    }
}

inline llll primeFactors(ll n) {
    llll factors; int c;
    ll idx=0, p=primes[0];
    while (n!=1 && (p*p<=n)) {
        c=0; while(n%p==0) c++, n/=p;
        if(c!=0) factors.first++, factors.second = p;
        p=primes[++idx];
    }
    if (n!=1) factors.first++, factors.second = n;
    return factors;
}


int main() {
    sieve();
    long long N;
    llll pf;
    while (scanf("%lld", &N) && N != 0) {
        if (N < 0) N = -N;
        if (N != 1) pf = primeFactors(N);
        if (pf.first <= 1 || N == 1) printf("-1\n");
        else printf("%lld\n", pf.second);
    }
    return 0;
}
