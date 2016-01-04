#include <cstdio>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) && n != 0) {
		n %= 9;
		printf("%d\n", n == 0? 9: n);
	}
	return 0;
}