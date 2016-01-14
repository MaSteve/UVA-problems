#include <cstdio>
using namespace std;

int main() {
	long i, j;
	while (scanf("%ld %ld", &i, &j) != EOF) {
		long diff = j-i;
		if (diff < 0) diff = i-j;
		printf("%ld\n",diff);
	}
	return 0;
}