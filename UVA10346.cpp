#include <cstdio>
using namespace std;

int main() {
	int n, k;
	while (scanf("%d %d", &n, &k) != EOF) {
		int sum = n;
		while (n >= k) {
			sum += n/k;
			n = n/k + n%k;
		}
		printf("%d\n", sum);
	}
	return 0;
}