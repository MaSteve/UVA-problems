#include <cstdio>
#include <cmath>

using namespace std;

long long power(long long b, long long e, long long mod) {
	if (e == 0) return 1;
	if (e == 1) return b%mod;
	long long aux = power(b, e/2, mod);
	aux = (aux*aux)%mod;
	if (e%2) aux = (aux*(b%mod))%mod;
	return aux;
}

int main() {
	int cases;
	scanf("%d", &cases);
	for (int i = 1; i <= cases; i++) {
		long long n, k, mod, res = 0;
		scanf("%lld %lld %lld", &n, &k, &mod);
		for (int j = 0; j < n; j++) {
			int val;
			scanf("%d", &val);
			res += val;
			res %= mod;
		}
		res *= (k%mod) * power(n, k-1, mod) ;
		res %= mod;
		printf("Case %d: %lld\n", i, res);
	}
	return 0;
}