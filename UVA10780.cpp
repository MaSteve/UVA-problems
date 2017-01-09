#include <iostream>
#include <bitset>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <climits>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef unordered_map<int, int> uii;

ll sieve_size;
bitset<100000001> bs;
vi primes;
uii fact[10001];
uii des[10001];

inline void sieve(ll upperbound = 10002) {
    sieve_size=upperbound+1;
    bs.set(); bs[0]=bs[1]=0;
    for (ll i=2; i<=sieve_size; i++) if(bs[i]) {
        for (ll j=i*i; j<=sieve_size; j+=i) bs[j] = 0;
        primes.push_back((int)i);
    }
}

inline void primeFactors(ll n, uii & factors) {
	int c;
	ll idx=0, p=primes[0];
	while (n!=1 && (p*p<=n)) {
		c=0; while(n%p==0) c++, n/=p;
		if(c!=0) factors[p] = c;
		p=primes[++idx];
	}
	if (n!=1) factors[n] = 1;
}


int main() {
    sieve();
    primeFactors(2, des[2]);
    fact[2] = des[2];
    for (int i = 3; i < 10000; i++) {
        primeFactors(i, des[i]);
        for (auto it = fact[i-1].begin(); it != fact[i-1].end(); ++it) {
            fact[i][it->first] = it->second;
        }
        for (auto it = des[i].begin(); it != des[i].end(); ++it) {
            fact[i][it->first] += it->second;
        }
    }
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        int m, n;
        cin >> m >> n;
        int mini = INT_MAX;
        for (auto it = des[m].begin(); it != des[m].end(); ++it) {
            mini = min(mini, fact[n][it->first] / it->second);
        }
        printf("Case %d:\n", c);
        if (mini != 0) printf("%d\n", mini);
        else printf("Impossible to divide\n");
    }
    return 0;
}
