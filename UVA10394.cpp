#include <cstdio>
#include <bitset>
#include <vector>
#include <unordered_set>
using namespace std;

typedef long long ll;

ll sieve_size; bitset<20000004> bs; 
vector<int> primes;
void sieve(ll upperbound) { 
	sieve_size=upperbound+1; bs.set(); bs[0]=bs[1]=0;
	for (ll i=2; i<=sieve_size; i++) if(bs[i]) {
		for (ll j=i*i; j<=sieve_size; j+=i) bs[j] = 0;
		primes.push_back((int)i);
	}
}

int main() {
	sieve(20000000);
	vector<int> v;
	int count = 0;
	for (int i = 0; i < primes.size()-1 && count < 100000; i++) 
		if(primes[i+1] == primes[i] + 2) { 
			v.push_back(primes[i]);
			count++;
		}
	int n;
	while (scanf("%d", &n) != EOF) {
		printf("(%d, %d)\n", v[n-1], v[n-1]+2);
	}
	return 0;
}