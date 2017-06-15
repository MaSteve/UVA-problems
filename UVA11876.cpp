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
bitset<10000010> bs;
vi primes;

inline void sieve(ll upperbound = 1000010) {
    sieve_size=upperbound+1;
    bs.set(); bs[0]=bs[1]=0;
    for (ll i=2; i<=sieve_size; i++) if(bs[i]) {
        for (ll j=i*i; j<=sieve_size; j+=i) bs[j] = 0;
        primes.push_back((int)i);
    }
}

vii factors;

inline void primeFactors(ll n) {
    factors.clear();
    int c;
    ll idx=0, p=primes[0];
    while (n!=1 && (p*p<=n)) {
        c=0; while(n%p==0) c++, n/=p;
        if(c!=0) factors.push_back(ii(p,c));
        p=primes[++idx];
    }
    if (n!=1) factors.push_back(ii(n,1));
}

int N[1000000], s = 0;

int divisors(int n) {
    int ret = 1;
    primeFactors(n);
    for (int i = 0; i < factors.size(); i++) {
        ret *= factors[i].second + 1;
    }
    return ret;
}

int main() {
    sieve();
    N[0] = 1;
    for (int i = 1; true; i++) {
        N[i] = N[i - 1] + divisors(N[i - 1]);
        s++;
        if (N[i] > 1000001) break;
    }
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        int A, B;
        cin >> A >> B;
        printf("Case %d: %ld\n", c, upper_bound(N, N + s, B) - lower_bound(N, N + s, A));
    }
    return 0;
}
