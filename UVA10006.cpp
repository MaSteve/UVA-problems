#include <iostream>
#include <bitset>
#include <unordered_set>
using namespace std;

typedef long long ll;
typedef unordered_set<int> usi;

ll sieve_size;
bitset<10000000> bs;
usi primes, carmichael;

void sieve(ll upperbound = 65000) {
    sieve_size=upperbound+1; bs.set(); bs[0]=bs[1]=0;
    for (ll i=2; i<=sieve_size; i++) if(bs[i]) {
        for (ll j=i*i; j<=sieve_size; j+=i) bs[j] = 0;
        primes.insert((int)i);
    }
}

long long pwr(long long b, long long e, long long mod) {
    if (e == 0) return 1%mod;
    if (e == 1) return b%mod;
    long long aux = pwr(b, e/2, mod);
    aux = (aux*aux)%mod;
    if (e%2) aux = (aux*(b%mod))%mod;
    return aux;
}

int main() {
    sieve();
    for (int i = 3; i <= 65000; i++) {
        if (primes.count(i)) continue;
        bool ok = true;
        for (int j = 2; j < i && ok; j++) {
            ok = pwr(j, i, i) == j;
        }
        if (ok) carmichael.insert(i);
    }
    int n;
    while (cin >> n && n) {
        if (carmichael.count(n)) printf("The number %d is a Carmichael number.\n", n);
        else printf("%d is normal.\n", n);
    }
    return 0;
}
