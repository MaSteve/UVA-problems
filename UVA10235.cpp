#include <iostream>
#include <bitset>
#include <unordered_set>
using namespace std;

typedef long long ll;
typedef unordered_set<int> usi;

ll sieve_size;
bitset<10000000> bs;
usi primes;

void sieve(ll upperbound) {
	sieve_size=upperbound+1; bs.set(); bs[0]=bs[1]=0;
	for (ll i=2; i<=sieve_size; i++) if(bs[i]) {
		for (ll j=i*i; j<=sieve_size; j+=i) bs[j] = 0;
		primes.insert((int)i);
	}
}

int reverse(int i) {
    int r = 0;
    while (i) {
        r = 10*r + i%10;
        i /= 10;
    }
    return r;
}

int main() {
    sieve(1000010);
    int n;
    while (cin >> n) {
        if (primes.count(n)) {
            int r = reverse(n);
            if (primes.count(r) && n != r) printf("%d is emirp.\n", n);
            else printf("%d is prime.\n", n);
        } else printf("%d is not prime.\n", n);
    }
    return 0;
}
