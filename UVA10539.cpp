#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;


typedef long long ll;
typedef vector<int> vi;
typedef vector<long> vl;

ll almost_primes_limit = 1000000000000;
ll sieve_size = 1000000;
bitset<10000010> bs;
vi primes;
vl almost_primes;


void sieve() {
    bs.set(); bs[0]=bs[1]=0;
    for (ll i=2; i<=sieve_size; i++) if(bs[i]) {
        for (ll j=i*i; j<=sieve_size; j+=i) bs[j] = 0;
        for (ll j=i*i; j<=almost_primes_limit; j*=i) almost_primes.push_back(j);
        primes.push_back((int)i);
    }
}

int main(){
	sieve();
	sort(almost_primes.begin(), almost_primes.end());
	//for(int i = 0; i < almost_primes.size(); i++) cout << almost_primes[i] << endl;
	int cases;
	cin >> cases;
	for(int i = 0; i < cases; i++){
		ll low, high;
		cin >> low >> high;
		cout << upper_bound (almost_primes.begin(), almost_primes.end(), high)-lower_bound (almost_primes.begin(), almost_primes.end(), low) << endl;
	}
	return 0;
}