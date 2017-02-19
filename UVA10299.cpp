#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll sieve_size;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound = 40000) {
    sieve_size=upperbound+1;
    bs.set(); bs[0]=bs[1]=0;
    for (ll i=2; i<=sieve_size; i++) if(bs[i]) {
        for (ll j=i*i; j<=sieve_size; j+=i) bs[j] = 0;
        primes.push_back((int)i);
    }
}

ll EulerPhi(ll n) {
    ll idx=0, p=primes[0], ans=n;
    while (n!=1 && (p*p<=n)) {
        if (n%p==0) ans-=ans/p;
        while (n%p==0) n/=p;
        p=primes[++idx];
    }
    if (n!=1) ans-=ans/n;
    return ans;
}

int main() {
    sieve();
    ll n;
    while (cin >> n && n) {
        if (n == 1) printf("0\n");
        else printf("%lld\n", EulerPhi(n));
    }
    return 0;
}
