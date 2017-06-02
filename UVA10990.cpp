#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

ll sieve_size;
bitset<10000010> bs;
vi primes;

inline void sieve(ll upperbound = 2000) {
    sieve_size=upperbound+1;
    bs.set(); bs[0]=bs[1]=0;
    for (ll i=2; i<=sieve_size; i++) if(bs[i]) {
        for (ll j=i*i; j<=sieve_size; j+=i) bs[j] = 0;
        primes.push_back((int)i);
    }
}

inline ll EulerPhi(ll n) {
    ll idx=0, p=primes[0], ans=n;
    while (n!=1 && (p*p<=n)) {
        if (n%p==0) ans-=ans/p;
        while (n%p==0) n/=p;
        p=primes[++idx];
    }
    if (n!=1) ans-=ans/n;
    return ans;
}

ll phi[2000001];
ll depth[2000001];
ll sum[2000001];

int main() {
    sieve();
    for (int i = 2; i <= 2000000; i++) {
        phi[i] = EulerPhi(i);
        if (phi[i] == 1) depth[i] = 1;
        else depth[i] = 1 + depth[phi[i]];
        sum[i] = sum[i-1] + depth[i];
    }
    int N;
    cin >> N;
    while (N--) {
        int m, n;
        cin >> m >> n;
        printf("%lld\n", sum[n] - sum[m-1]);
    }
    return 0;
}
