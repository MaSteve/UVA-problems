#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int N, B, H, W;
	while (scanf("%d %d %d %d", &N, &B, &H, &W) != EOF) {
		int cost = B + 1;
		for (int i = 0; i < H; i++) {
			int p;
			scanf("%d", &p);
			for (int j = 0; j < W; j++) {
				int rooms;
				scanf("%d", &rooms);
				if (rooms >= N) cost = min(cost, p*N);
			}
		}
		if (cost < B) printf("%d\n", cost);
		else printf("stay home\n");
	}
	return 0;
}