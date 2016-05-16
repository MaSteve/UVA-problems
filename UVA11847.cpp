#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) && n != 0) {
		printf("%d\n", int(floor(log2(n))));
	}
	return 0;
}