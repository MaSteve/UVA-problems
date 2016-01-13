#include <cstdio>
using namespace std;

long proc(long A, long l) {
	if (A > l) return 0;
	if (A == 1) return 1;
	return proc(A%2 == 0? A/2: (3*A) + 1, l) + 1;
}

int main() {
	long A, l;
	int i = 1;
	while (scanf("%ld %ld", &A, &l) && !(A == -1 && l == -1)) {
		printf("Case %d: A = %ld, limit = %ld, number of terms = %ld\n", i, A, l, proc(A, l));
		i++;
	}
	return 0;
}