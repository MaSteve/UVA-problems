#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

ll sieve_size;
bitset<100000001> bs;
vi primes;

inline void sieve(ll upperbound = 1000000) {
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

long double dp[1000010];

long double proc(int N) {
    if (N == 1) return 0;
    if (dp[N] == 0) {
        vii factors;
        primeFactors(N, factors);
        long double divisors = factors.size();
        int primnum = upper_bound(primes.begin(), primes.end(), N) - primes.begin();
        long double E = 0;
        for (int i = 0; i < factors.size(); i++) {
            E += proc(N/factors[i].first)/primnum;
        }
        dp[N] = (E+1)*primnum/divisors;
    }
    return dp[N];
}

int main() {
    sieve();
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        int N;
        cin >> N;
        printf("Case %d: %.10Lf\n", c, proc(N));
    }
    return 0;
}
