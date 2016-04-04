#include <cstdio>
using namespace std;

bool solopt[20], sol[20];
int tracks[20];
int N, T, costopt, maxi;

void proc(int pos, int cost) {
	if (cost <= N && cost + maxi*(T-pos) > costopt) {
		if (pos == T) {
			if (cost > costopt) {
				for (int i = 0; i < T; i++) solopt[i] = sol[i];
				costopt = cost;
			}
		} else {
			sol[pos] = true;
			proc(pos + 1, cost + tracks[pos]);
			sol[pos] = false;
			proc(pos + 1, cost);
		}
	}
}

int main() {
	while (scanf("%d", &N) != EOF) {
		scanf("%d", &T);
		maxi = 0;
		for (int i = 0; i < T; i++) scanf("%d", &tracks[i]), sol[i] = solopt[i] = false, maxi = tracks[i] > maxi? tracks[i]: maxi;
		costopt = 0;
		proc(0, 0);
		for (int i = 0; i < T; i++) {
			if (solopt[i]) {
				printf("%d ", tracks[i]);
			}
		}
		printf("sum:%d\n", costopt);
	}
	return 0;
}