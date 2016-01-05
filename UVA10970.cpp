#include <cstdio>
using namespace std;

int main() {
	int N, M;
	while (scanf("%d %d", &N, &M) != EOF) {
		printf("%d\n", N*M - 1);
	}
	return 0;
}