#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int i = 1;
	int R, N;
	while (scanf("%d %d", &R, &N) != EOF && !(R == 0 && N == 0)) {
		int suffixes = (R-N)/N;
		if ((R-N)%N) suffixes++;
		if (R <= N) suffixes = 0;
		printf("Case %d: ", i);
		if (suffixes <= 26) printf("%d\n", suffixes);
		else printf("impossible\n");
		i++;
	}
	return 0;
}