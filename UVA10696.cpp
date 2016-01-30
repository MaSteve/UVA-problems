#include <cstdio>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) && n != 0) printf("f91(%d) = %d\n", n,(n >= 102? n-10: 91));
	return 0;
}