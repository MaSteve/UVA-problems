#include <cstdio>
using namespace std;

int main() {
	int cases;
	scanf("%d", &cases);
	for (int i = 0; i < cases; i++) {
		long long s, d, r1, r2;
		scanf("%lld %lld", &s, &d);
		r1 = (s+d)/2;
		r2 = s-r1;
		if (r2 >=0 && r1 - r2 == d) printf("%lld %lld\n", r1, r2);
		else printf("impossible\n");
	}
	return 0;
}