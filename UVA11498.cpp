#include <cstdio>
using namespace std;

int main() {
	int K;
	while (scanf("%d", &K) && K != 0) {
		int N, M;
		scanf("%d %d", &N, &M);
		for (int i = 0; i < K; i++) {
			int X, Y;
			scanf("%d %d", &X, &Y);
			if (X > N) {
				if (Y > M) printf("NE\n");
				else if (Y < M) printf("SE\n");
				else printf("divisa\n");

			} else if (X < N) {
				if (Y > M) printf("NO\n");
				else if (Y < M) printf("SO\n");
				else printf("divisa\n");
			}
			else printf("divisa\n");
		}
	}
	return 0;
}