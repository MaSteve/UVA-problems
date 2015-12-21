#include <cstdio>
using namespace std;

int main() {
	long N;
	while (scanf("%ld", &N) && N>=0) {
		printf("%ld\n", 1+(((N+1)*N)/2));
	}
	return 0;
}