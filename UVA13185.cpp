// You can also see UVA13194.cpp
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

vii v;
long long dp[20];

long long proc(int i) {
    if (i >= v.size()) return 1;
    if (dp[i] == -1) {
        long long ret = 0;
        for (int j = 0; j <= v[i].second; j++)
            ret += pow(v[i].first, j)*proc(i+1);
        dp[i] = ret;
    }
    return dp[i];
}

int main() {
    sieve(100);
    int T;
    cin >> T;
    int pot[20];
    while (T--) {
        long long N;
        cin >> N;
        primeFactors(N, v);
        for (int i = 0; i < v.size(); i++) pot[i] = 0, dp[i] = -1;
        long long ret = proc(0) - N;
        if (ret == N) printf("perfect\n");
        else if (ret > N) printf("abundant\n");
        else printf("deficient\n");
    }
    return 0;
}
