#include <cstdio>
using namespace std;

int main() {
	long long ways[30003];
	for (int i = 0; i < 30003; i++) ways[i] = 1;
	for (int i = 10; i < 30003; i++) ways[i] += ways[i-10];
	for (int i = 20; i < 30003; i++) ways[i] += ways[i-20];
	for (int i = 50; i < 30003; i++) ways[i] += ways[i-50];
	for (int i = 100; i < 30003; i++) ways[i] += ways[i-100];
	for (int i = 200; i < 30003; i++) ways[i] += ways[i-200];
	for (int i = 500; i < 30003; i++) ways[i] += ways[i-500];
	for (int i = 1000; i < 30003; i++) ways[i] += ways[i-1000];
	for (int i = 2000; i < 30003; i++) ways[i] += ways[i-2000];
	for (int i = 5000; i < 30003; i++) ways[i] += ways[i-5000];
	for (int i = 10000; i < 30003; i++) ways[i] += ways[i-10000];
	for (int i = 0; i < 5; i++) ways[i] = 0;
	int n, i, f;
	while (scanf("%d.%d", &i, &f) != EOF && !(i == 0 && f == 0)) {
		n = (i*100)+f;
		printf("%3d.%02d%17lld\n", i, f, ways[n]);
	}
	return 0;
}