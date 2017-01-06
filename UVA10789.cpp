#include <iostream>
#include <bitset>
#include <unordered_set>
using namespace std;

typedef long long ll;

ll sieve_size;
bitset<10000010> bs;
unordered_set<int> primes;

void sieve(ll upperbound = 2002) {
    sieve_size=upperbound+1;
    bs.set(); bs[0]=bs[1]=0;
    for (ll i=2; i<=sieve_size; i++) if(bs[i]) {
        for (ll j=i*i; j<=sieve_size; j+=i) bs[j] = 0;
        primes.insert((int)i);
    }
}

int main() {
    sieve();
    int bucket[128], T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        for (int i = 0; i < 128; i++) bucket[i] = 0;
        string s;
        cin >> s;
        for (int i = 0; i < s.length(); i++) bucket[s[i]]++;
        printf("Case %d: ", c);
        bool empty = true;
        for (int i = 0; i < 128; i++) if (primes.count(bucket[i])) printf("%c", i), empty = false;
        if (empty) printf("empty");
        printf("\n");
    }
    return 0;
}
