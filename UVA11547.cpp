#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	int cases;
	scanf("%d", &cases);
	for (int i = 0; i < cases; i++) {
		int n;
		scanf("%d", &n);
		n = fabs((((n*315)+36962)%100)/10);
		printf("%d\n", n);
	}
	return 0;
}