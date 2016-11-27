#include <iostream>
#include <bitset>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef unordered_map<int, int> mii;

ll sieve_size;
bitset<10000010> bs;
vi primes;

void sieve(long long upperbound = 1000001) {
    sieve_size=upperbound+1;
    bs.set(); bs[0]=bs[1]=0;
    for (ll i=2; i<=sieve_size; i++) if(bs[i]) {
        for (ll j=i*i; j<=sieve_size; j+=i) bs[j] = 0;
        primes.push_back((int)i);
    }
}

mii primeFactors(ll n) {
    mii factors; int c;
    ll idx=0, p=primes[0];
    while (n!=1 && (p*p<=n)) {
        c=0; while(n%p==0) c++, n/=p;
        if(c!=0) factors.insert(ii(p,c)); p=primes[++idx];
    }
    if (n!=1) factors.insert(ii(n,1));
    return factors;
}


int main() {
    sieve();
    mii last;
    long long values[1000002];
    values[0] = 0;
    values[1] = 1;
    for (int i = 2; i <= 1000000; i++) {
        values[i] = values[i-1];
        mii auxi = primeFactors(i);
        for (auto it = auxi.begin(); it != auxi.end(); ++it) {
            int ex = last[it->first];
            if (it->second > ex) {
                last[it->first] = it->second;
                values[i] *= pow(it->first, it->second - ex);
                while (values[i] % 10 == 0) values[i] /= 10;
                values[i] %= 10000000;
            }
        }
        values[i-1] %= 10;
    }
    values[1000000] %= 10;
    int N;
    while (scanf("%d", &N) && N != 0) {
        printf("%lld\n", values[N]);
    }
    return 0;
}
