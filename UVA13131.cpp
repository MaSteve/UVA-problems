#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ll sieve_size;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound) {
    sieve_size=upperbound+1;
    bs.set(); bs[0]=bs[1]=0;
    for (ll i=2; i<=sieve_size; i++) if(bs[i]) {
        for (ll j=i*i; j<=sieve_size; j+=i) bs[j] = 0;
        primes.push_back((int)i);
    }
}

void primeFactors(ll n, vii & factors) {
    int c;
    factors.clear();
    ll idx=0, p=primes[0];
    while (n!=1 && (p*p<=n)) {
        c=0; while(n%p==0) c++, n/=p;
        if(c!=0) factors.push_back(ii(p,c));
        p=primes[++idx];
    }
    if (n!=1) factors.push_back(ii(n,1));
}

int main() {
    sieve(50000);
    int T;
    cin >> T;
    int pot[20];
    vii v;
    while (T--) {
        int N, K;
        cin >> N >> K;
        primeFactors(N, v);
        for (int i = 0; i < v.size(); i++) pot[i] = 0;
        int ret = 0;
        while (true) {
            int val = 1;
            for (int i = 0; i < v.size(); i++) {
                val *= pow(v[i].first, pot[i]);
            }
            if (val % K != 0) ret += val;
            if (val == N) break;
            int j = 0;
            bool ok = true;
            do {
                ok = true;
                pot[j]++;
                if (pot[j] > v[j].second) pot[j] = 0, ok = false;
                j++;
            } while (!ok && j < v.size());
        }
        printf("%d\n", ret);
    }
    return 0;
}
