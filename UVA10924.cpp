#include <iostream>
#include <unordered_set>
#include <bitset>
#include <string>
#include <cctype>
using namespace std;

typedef long long ll;

ll sieve_size;
bitset<10000010> bs;
unordered_set<int> primes;
void sieve(ll upperbound) {
	sieve_size=upperbound+1; bs.set(); bs[0]=bs[1]=0;
	for (ll i=2; i<=sieve_size; i++) if(bs[i]) {
		for (ll j=i*i; j<=sieve_size; j+=i) bs[j] = 0;
		primes.insert((int)i);
	}
}

int main() {
	sieve(2000);
	primes.insert(1);
	string s;
	while (cin >> s) {
		int val = 0;
		for (int i = 0; i < s.length(); i++) {
			if (isupper(s[i])) val += 27 + (s[i]-'A');
			else if (islower(s[i])) val += 1 + (s[i]-'a');
		}
		if (primes.count(val)) cout << "It is a prime word." << endl;
		else cout << "It is not a prime word." << endl;
	}
	return 0;
}