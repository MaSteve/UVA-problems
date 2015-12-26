#include <cstdio>
using namespace std;

unsigned int comb[101][101];

unsigned int proc(int n, int m) {
	if(comb[n][m] == 0) {
		comb[n][m] = n == m || m == 0? 1: proc(n-1, m-1) + proc(n-1, m);
	}
	return comb[n][m];
}

int main() {
	int n, m;
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++) comb[i][j] = 0;
	while (scanf("%d %d", &n, &m) && !(n == 0 && m == 0)) {
		unsigned int c = proc(n, m);
		printf("%d things taken %d at a time is %d exactly.\n", n, m, c);
	}
	return 0;
}