#include <cstdio>
using namespace std;

int main() {
	int n;
	int mask[101];
	while (scanf("%d", &n) && n != 0) {
		for (int i = 0; i < n; i++) mask[i] = 0;
		int sol = -1;
		for (int l = 1; l < 100 && sol == -1; l++) {
			int pos = 0;
			for (int i = 0; i < n; i++) {
				mask[pos] = l;
				if (pos == 12) {
					if (i == n - 1) sol = l;
					break;
				}
				for (int j = 0; j < l; j++) {
					do {
						pos++;
						pos%=n;
					} while (mask[pos] == l);
				}
			}
		}
		printf("%d\n", sol);
	}
	return 0;
}