#include <cstdio>
using namespace std;

int main() {
	unsigned int n, a, b;
	while (scanf("%d", &n) && n != 0) {
		a = b = 0;
		int bits = 1;
		for (int i = 0; i < 32; i++) {
			int val = n & (1 << i);
			if (val) {
				if (bits % 2) a |= (1 << i);
				else b |= (1 << i);
				bits++;
			}
		}
		printf("%d %d\n", a, b);
	}
	return 0;
}