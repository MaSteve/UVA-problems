#include <cstdio>
using namespace std;

long long power(long long b, long long e, long long mod) {
	if (e == 0) return 1%mod;
	if (e == 1) return b%mod;
	long long aux = power(b, e/2, mod);
	aux = (aux*aux)%mod;
	if (e%2) aux = (aux*(b%mod))%mod;
	return aux;
}

int main() {
	int m;
	scanf("%d", &m);
	while (m--) {
		unsigned int x, y, n;
		scanf("%d %d %d", &x, &y, &n);
		printf("%lld\n", power(x, y, n));
	}
	return 0;
}