#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	int n;
	printf("PERFECTION OUTPUT\n");
	while (scanf("%d", &n) && n != 0) {
		printf("%5d  ", n);
		int s = n == 1? 0: 1;
		for (int i = 2; i < sqrt(n); i++)
			if(n % i == 0) s += i + n/i;
		if(s == n) printf("PERFECT\n");
		else if (s > n) printf("ABUNDANT\n");
		else printf("DEFICIENT\n");
	}
	printf("END OF OUTPUT\n");
	return 0;
}