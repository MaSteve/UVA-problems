#include <cstdio>
using namespace std;

int main() {
	int cases;
	scanf("%d", &cases);
	for (int i = 1; i <= cases; i++) {
		int N, K, P;
		scanf("%d %d %d", &N, &K, &P);
		int r = (K+P)%N;
		printf("Case %d: %d\n", i, r == 0? N: r);
	}
	return 0;
}