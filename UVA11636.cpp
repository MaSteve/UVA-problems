#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	int N, X = 1;
	while (scanf("%d", &N) && N > 0) {
		printf("Case %d: %d\n", X++, (int)ceil(log2(N)));
	}
	return 0;
}