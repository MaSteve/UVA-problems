#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int v[10002];
	int N;
	while (scanf("%d", &N) != EOF) {
		int mean = 0;
		for (int i = 0; i < N; i++) {
			int note;
			scanf("%d", &note);
			v[i] = note;
			mean += note;
		}
		if (mean % N != 0) printf("-1\n");
		else {
			mean /= N;
			int moves = 1;
			for (int i = 0; v[i] < mean; i++) {
				moves += mean - v[i];
			}
			printf("%d\n", moves);
		}
	}
	return 0;
}