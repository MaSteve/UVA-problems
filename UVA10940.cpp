#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) && n != 0) {
		if (n == 1) printf("1\n");
		else if (n == 2) printf("2\n");
		else {
			int l = floor(log2(n));
			int sol = (n & ~(1<<l)) * 2;
			if (sol == 0) sol = n;
			printf("%d\n", sol);
		}
	}
	return 0;
}