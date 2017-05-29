// I hope you enjoy this video:  https://www.youtube.com/watch?v=MxiTG96QOxw
#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll sieve_size;
bitset<33010> bs;
vi primes;

inline void sieve(ll upperbound = 33000) {
    sieve_size=upperbound+1;
    bs.set(); bs[0]=bs[1]=0;
    for (ll i=2; i<=sieve_size; i++) if(bs[i]) {
        for (ll j=i*i; j<=sieve_size; j+=i) bs[j] = 0;
        primes.push_back(i);
    }
}

int main() {
    sieve();
    int n;
    while (cin >> n && n != 0) {
        int res = 0;
        for (int i = 0; i < primes.size(); i++) {
            if (n - primes[i] < primes[i]) break;
            if (bs[n - primes[i]]) res++;
        }
        printf("%d\n", res);
    }
    return 0;
}
