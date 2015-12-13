#include <cstdio>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	while (N != 0) {
		int current = 0, best = 0;
		for (int i = 0; i < N; i++) {
			int bet;
			scanf("%d", &bet);
			if (bet > current + bet) current = bet;
			else current += bet;
			if (current > best) best = current;
		}
		if (best == 0) printf("Losing streak.\n");
		else printf("The maximum winning streak is %d.\n", best);
		scanf("%d", &N);
	}
	return 0;
}