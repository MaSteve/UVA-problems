#include <cstdio>
using namespace std;

int main() {
	unsigned int a, b;
	while (scanf("%u %u", &a, &b) != EOF) printf("%d\n", a^b);
	return 0;
}