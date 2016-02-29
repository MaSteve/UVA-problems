#include <cstdio>
using namespace std;

int main() {
	int cases;
	scanf("%d", &cases);
	for (int i = 1; i <= cases; i++) {
		int N, max = 0, s;
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			scanf("%d", &s);
			if (s > max) max = s;
		}
		printf("Case %d: %d\n", i, max);
	}
	return 0;
}