#include <cstdio>
#include <bitset>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

ll sieve_size; 
bitset<10000000> bs; 
vi primes;

void sieve(ll upperbound) {
	sieve_size=upperbound+1; bs.set(); bs[0]=bs[1]=0;
	for (ll i=2; i<=sieve_size; i++) if(bs[i]) {
			for (ll j=i*i; j<=sieve_size; j+=i) bs[j] = 0;
			primes.push_back((int)i);
	}
} vii primeFactors(ll n) {
	vii factors; int c; ll idx=0, p=primes[0];
	while (n!=1 && (p*p<=n)) {
			c=0; while(n%p==0) c++, n/=p;
			if(c!=0) factors.push_back(ii(p,c));
			p=primes[++idx];
	} if (n!=1) factors.push_back(ii(n,1));
	return factors;
}

int main() {
	int n;
	sieve(46350);
	while (scanf("%d", &n) && n != 0) {
		vii factors = primeFactors(fabs(n));
		printf("%d = ", n);
		if (n < 0) printf("-1 x ");
		bool first = false;
		for (int i = 0; i < factors.size(); i++) {
			for (int j = 0; j < factors[i].second; j++){
				if (first) printf(" x ");
				else first = true;
				printf("%d", factors[i].first);
			}
		}
		printf("\n");
	}
	return 0;
}