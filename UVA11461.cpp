#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	int a, b;
	while (scanf("%d %d", &a, &b) && !(a == 0 && b == 0)) {
		a = ceil(sqrt(a));
		b = floor(sqrt(b));
		printf("%d\n", b-a+1);
	}
	return 0;
}