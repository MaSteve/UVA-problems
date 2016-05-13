#include <cstdio>
using namespace std;

int main() {
	int n, m, c;
	while (scanf("%d %d %d", &n, &m, &c) && !(n == 0 && m == 0 && c == 0)) {
		int dim = ((n-7)*(m-7))/2;
		if ((n-7)%2 && (m-7)%2 && c == 1) {
			printf("%d\n", dim + 1);
		} else printf("%d\n", dim);
	}
	return 0;
}