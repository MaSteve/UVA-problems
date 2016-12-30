#include <iostream>
#include <bitset>
#include <vector>
#include <utility>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

ll sieve_size;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound = 70000) {
    sieve_size=upperbound+1;
    bs.set(); bs[0]=bs[1]=0;
    for (ll i=2; i<=sieve_size; i++) if(bs[i]) {
        for (ll j=i*i; j<=sieve_size; j+=i) bs[j] = 0;
        primes.push_back((int)i);
    }
}

vii primeFactors(ll n) {
    vii factors; int c;
    ll idx=0, p=primes[0];
    while (n!=1 && (p*p<=n)) {
        c=0;
        while(n%p==0) c++, n/=p;
        if(c!=0) factors.push_back(ii(p,c)); p=primes[++idx];
    }
    if (n!=1) factors.push_back(ii(n,1));
    return factors;
}

ll gcd(ll n, ll m) {
	ll auxi;
	if (m > n) {
		auxi = n;
		n = m, m = auxi;
	}
	while (m > 0) {
		auxi = n;
		n = m, m = auxi%m;
	}
	return n;
}

int main() {
    sieve();
    long long n;
    while (cin >> n && n != 0) {
        bool neg = (n < 0);
        if (neg) n = -n;
        vii factors = primeFactors(n);
        int p = 0;
        for (int i = 0; i < factors.size(); i++) {
            p = gcd(factors[i].second, p);
        }
        while (neg && p%2 == 0) p /= 2;
        printf("%d\n", p);
    }
    return 0;
}
