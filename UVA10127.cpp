#include <cstdio>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int i = 1;
		int cont = 1;
		while (i % n != 0) i = (i*10 + 1)%n, cont++;
		printf("%d\n", cont);
	}
	return 0;
}