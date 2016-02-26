#include <cstdio>
using namespace std;

int main() {
	long long ways[10003];
	for (int i = 0; i < 10003; i++) ways[i] = 1;
	for (int j = 2; j <= 21; j++) {
		int pot = j*j*j;
		for (int i = pot; i < 10003; i++) ways[i] += ways[i-pot];
	}
	int n;
	while (scanf("%d", &n) != EOF) {
		printf("%lld\n", ways[n]);
	}
	return 0;
}