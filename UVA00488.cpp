#include <cstdio>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	while (N--) {
		int a, f;
		scanf("%d %d", &a, &f);
		while (f--) {
			for (int i = 1; i <= a; i++) {
				for (int j = 0; j < i; j++) printf("%d", i);
				printf("\n");
			}
			for (int i = a-1; i > 0; i--) {
				for (int j = 0; j < i; j++) printf("%d", i);
				printf("\n");
			}
			if (N != 0 || f != 0) printf("\n");
		}
	}
	return 0;
}