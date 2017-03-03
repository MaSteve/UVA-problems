#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

ll sieve_size;
bitset<100000001> bs;
vi primes;

inline void sieve(ll upperbound = 40000) {
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

vii v;

bool check(int n) {
    v.clear();
    primeFactors(n, v);
    if (v.size() == 1 && v[0].second == 1) return false;
    int s1 = 0, s2 = 0;
    while (n) {
        s1 += n%10;
        n /= 10;
    }
    for (int i = 0; i < v.size(); i++) {
        int val = v[i].first;
        int acum = 0;
        while (val) {
            acum += val%10;
            val /= 10;
        }
        acum *= v[i].second;
        s2 += acum;
    }
    return (s1 == s2);
}

int main() {
    sieve();
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        n++;
        while (!check(n)) n++;
        printf("%d\n", n);
    }
    return 0;
}
