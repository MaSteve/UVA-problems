#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
#include <climits>
#include <sstream>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

ll sieve_size;
bitset<100000001> bs;
vi primes;

inline void sieve(ll upperbound = 200) {
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
    string s;
    while (getline(cin, s) && s != "0") {
        stringstream ss(s);
        int p, e, n = 1;
        while (ss >> p >> e) {
            int pot = 1;
            for (int i = 0; i < e; i++) pot *= p;
            n *= pot;
        }
        n--;
        vii factors;
        primeFactors(n, factors);
        for (int i = factors.size() - 1; i >= 0; i--) {
            if (i != factors.size() - 1) printf(" ");
            printf("%d %d", factors[i].first, factors[i].second);
        }
        printf("\n");
    }
    return 0;
}
