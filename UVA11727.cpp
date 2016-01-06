#include <iostream>
using namespace std;

int main() {
	int cases;
	scanf("%d", &cases);
	for (int i = 1; i <= cases; i++) {
		int n1, n2, n3;
		scanf("%d %d %d", &n1, &n2, &n3);
		printf("Case %d: %d\n", i, n1 + n2 + n3 - min(n1, min(n2, n3)) - max(n1, max(n2, n3)));
	}
	return 0;
}