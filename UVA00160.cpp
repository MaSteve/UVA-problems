#include <cstdio>
#include <vector>
#include <utility>
#include <bitset>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef unordered_map<int, int> uii;

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

uii primeFactors(ll n) {
	uii factors; int c;
	ll idx=0, p=primes[0];
	while (n!=1 && (p*p<=n)) {
		c=0; while(n%p==0) c++, n/=p; if(c!=0) factors.insert(ii(p,c)); p=primes[++idx];
	}
	if (n!=1) factors.insert(ii(n,1));
	return factors;
}

vector<uii> fact;

int main() {
	sieve(101);
	for (int i = 2; i <= 100; i++) fact.push_back(primeFactors(i));
	for (int i = 3; i <= 100; i++) {
		uii prev = fact[i-3];
		for (auto it = prev.begin(); it != prev.end(); ++it) {
			ii f = *it;
			if (fact[i-2].count(f.first)) f.second += fact[i-2][f.first];
			fact[i-2][f.first] = f.second;
		}
	}
	int n;
	while (scanf("%d", &n) && n != 0) {
		printf("%3d! =", n);
			for (int i = 0, cont = 0; i < primes.size(); i++) {
				if (fact[n-2].count(primes[i])) {
					if(cont != 0 && cont % 15 == 0) printf("\n      ");
					printf(" %2d", fact[n-2][primes[i]]); cont++;
				}
			}
		printf("\n");
	}
	return 0;
}