#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	unsigned int N;
	while (scanf("%d", &N) && N != 0) {
		int sq = sqrt(N);
		if (sq*sq == N) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}