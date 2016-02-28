#include <cstdio>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		int up = 0, down = 0, h;
		int blocks;
		scanf("%d", &blocks); scanf("%d", &h);
		for (int j = 1; j < blocks; j++) {
			int next;
			scanf("%d", &next);
			if (next > h) up++;
			else if (next < h) down++;
			h = next;
		}
		printf("Case %d: %d %d\n", i, up, down);
	}
	return 0;
}