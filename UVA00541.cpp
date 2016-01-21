#include <cstdio>
using namespace std;

int main() {
	int n;
	int sums[100];
	while (scanf("%d", &n) && n != 0) {
		int row = -1;
		bool corrupt = false;
		for (int i = 0; i < n; i++) sums[i] = 0;
		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = 0; j < n; j++) {
				int bit;
				scanf("%d", &bit);
				if (bit) sums[j]++, sum++;
			}
			if (sum % 2 == 1){
				if (row == -1) row = i;
				else corrupt = true;
			}
		}
		int col = -1;
		for (int i = 0; i < n && !corrupt; i++) {
			if (sums[i] % 2 == 1) {
				if (col == -1) col = i;
				else corrupt = true;
			}
		}
		if (corrupt) printf("Corrupt\n");
		else if (row == -1 && col == -1) printf("OK\n");
		else {
			if (row == -1 || col == -1) printf("Corrupt\n");
			else printf("Change bit (%d,%d)\n", row + 1 , col + 1);
		}
	}
	return 0;
}