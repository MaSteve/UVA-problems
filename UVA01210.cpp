#include <iostream>
#include <bitset>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef unordered_map<int, int> uii;
typedef unordered_map<int, uii> uiuii;

ll sieve_size;
bitset<100000001> bs;
vi primes;
uiuii dp;

inline void sieve(ll upperbound = 10002) {
    sieve_size=upperbound+1;
    bs.set(); bs[0]=bs[1]=0;
    for (ll i=2; i<=sieve_size; i++) if(bs[i]) {
        for (ll j=i*i; j<=sieve_size; j+=i) bs[j] = 0;
        primes.push_back((int)i);
    }
}

int proc(int n, int next) {
    if (n == 0) return 1;
    if (next >= primes.size()) return 0;
    if (!(dp.count(n) && dp[n].count(next))) {
        int val = 0;
        if (n - primes[next] >= 0) val = proc(n - primes[next], next + 1);
        dp[n][next] = val;
    }
    return dp[n][next];
}

int main() {
    sieve();
    int n;
    while (cin >> n && n != 0) {
        int val = 0;
        for (int i = 0; i < primes.size(); i++) {
            if (n - primes[i] < 0) break;
            val += dp[n][i] = proc(n - primes[i], i + 1);
        }
        printf("%d\n", val);
    }
    return 0;
}
