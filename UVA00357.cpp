#include <cstdio>
using namespace std;

int main() {
	long long ways[30003];
	for (int i = 0; i < 30003; i++) ways[i] = 1;
	for (int i = 5; i < 30003; i++) ways[i] += ways[i-5];
	for (int i = 10; i < 30003; i++) ways[i] += ways[i-10];
	for (int i = 25; i < 30003; i++) ways[i] += ways[i-25];
	for (int i = 50; i < 30003; i++) ways[i] += ways[i-50];
	int n;
	while (scanf("%d", &n) != EOF) {
		if (ways[n] > 1) printf("There are %lld ways to produce %d cents change.\n", ways[n], n);
		else printf("There is only 1 way to produce %d cents change.\n", n);
	}
	return 0;
}