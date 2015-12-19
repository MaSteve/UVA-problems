#include <cstdio>
#include <cmath>
#include <vector>
#include <bitset>
#include <utility>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

ll sieve_size;
bitset<10000010> bs;
vi primes;

int mod(int a, int b) {return ((a %b)+b) %b;}

void sieve(ll upperbound) {
    sieve_size=upperbound+1;
    bs.set(); bs[0]=bs[1]=0;
    for (ll i=2; i <= sieve_size; i++) if (bs[i]) {
        for (ll j=i*i; j<=sieve_size; j+=i) bs[j] = 0;
        primes.push_back((int)i);
    }
}

vii primeFactors(ll n) {
    vii factors; int c;
    ll idx=0, p=primes[0];
    while (n!=1 && (p*p<=n)) {
		c=0; 
		while (n%p==0) c++, n/=p; 
		if (c!=0) factors.push_back(ii(p,c)); 
		p=primes[++idx];
    }
    if (n!=1) factors.push_back(ii(n,1));
    return factors;
}


int main() {
	sieve(65600);
	unsigned int N;
	while (scanf("%d", &N) && N != 0) {
		int cont = 1;
		if(N != 1){
			vii factors = primeFactors(N);
			for(int i = 0; i < factors.size(); i++) cont *= factors[i].second+1;
		}
		if (cont%2 == 0) printf("no\n");
		else printf("yes\n");
	}
}