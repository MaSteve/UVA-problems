#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	long long S, D;
	while (scanf("%lld %lld", &S, &D) != EOF) {
		long long n = (-1+ceil(sqrt(1-4*(S-S*S-2*D))));
		printf("%lld\n", n/2 + n%2);
	}
	return 0;
}