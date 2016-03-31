#include <cstdio>
using namespace std;

int n;
int val[13], sel[6];

void proc(int pval, int psel) {
	if (pval >= n) return;
	sel[psel] = val[pval];
	if (psel == 5) {
		bool first = false;
		for (int i = 0; i < 6; i++) {
			if (first) printf(" ");
			else first = true;
			printf("%d", sel[i]);
		}
		printf("\n");
	} else proc(pval + 1, psel + 1);
	if (n - pval > 6 - psel) proc(pval + 1, psel);
}

int main() {
	bool first = false;
	while (scanf("%d", &n) && n != 0) {
		if (first) printf("\n");
		else first = true;
		for (int i = 0; i < n; i++) scanf("%d", &val[i]);
		proc(0, 0);
	}
	return 0;
}