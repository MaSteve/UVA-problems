#include <iostream>
#include <bitset>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

ll sieve_size;
bitset<100000001> bs;
vi primes, dprimes;
unordered_set<int> s;

inline void sieve(ll upperbound = 1000000) {
    sieve_size=upperbound+1;
    bs.set(); bs[0]=bs[1]=0;
    for (ll i=2; i<=sieve_size; i++) if(bs[i]) {
        for (ll j=i*i; j<=sieve_size; j+=i) bs[j] = 0;
        primes.push_back((int)i);
        s.insert((int)i);
    }
}

int main() {
    sieve();
    for (int i = 0; i < primes.size(); i++) {
        int val = primes[i], sum = 0;
        while (val) sum += val%10, val /= 10;
        if (s.count(sum)) dprimes.push_back(primes[i]);
    }
    int N;
    cin >> N;
    while (N--) {
        int t1, t2;
        cin >> t1 >> t2;
        printf("%ld\n", upper_bound(dprimes.begin(), dprimes.end(), t2) - lower_bound(dprimes.begin(), dprimes.end(), t1));
    }
    return 0;
}
