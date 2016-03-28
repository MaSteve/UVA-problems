#include <cstdio>
using namespace std;

int main() {
	int N, M;
	while (scanf("%d %d", &N, &M) != EOF) {
		int cont = 0;
		for (int i = 0; i < N; i++) {
			bool add = true;
			for (int j = 0; j < M; j++) {
				int score;
				scanf("%d", &score);
				if (score == 0) add = false;
			}
			if (add) cont++;
		}
		printf("%d\n", cont);
	}
	return 0;
}