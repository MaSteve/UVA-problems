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
	int b, p, m;
	while (scanf("%d %d %d", &b, &p, &m) == 3) {
		printf("%lld\n", power(b, p, m));
	}
	return 0;
}