#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int n, x, y;
	while (scanf("%d", &n) && n != 0) {
		int s = ceil(sqrt(n));
		int pos = n - (s-1)*(s-1);
		int lim = s*s - (s-1)*(s-1);
		if (s % 2 == 0) {
			x = pos > lim/2? s: pos, y = pos > lim/2? lim - pos + 1: s;
		} else {
			y = pos > lim/2? s: pos, x = pos > lim/2? lim - pos + 1: s;
		}
		printf("%d %d\n", x, y);
	}
	return 0;
}