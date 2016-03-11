#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) && n >= 0) {
		int s = ceil(sqrt(n));
		int sol = -1;
		for (int i = 2; i <= s; i++) {
			bool ok = true;
			int val = n, cont = 0;
			while (ok) {
				if (val % i == 0) break;
				else if ((val - 1) % i == 0) val = val - 1 - ((val - 1)/i);
				else ok = false;
				cont++;
			}
			if (ok && cont == i) sol = i;
		}
		if (sol != -1) printf("%d coconuts, %d people and 1 monkey\n", n, sol);
		else printf("%d coconuts, no solution\n", n);
	}
	return 0;
}