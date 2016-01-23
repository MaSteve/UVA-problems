#include <cstdio>
using namespace std;

int main() {
	int n;
	int count[7490];
	for (int i = 0; i < 7490; i++) count[i] = 1;
	for (int i = 5; i < 7490; i++) count[i] += count[i-5];
	for (int i = 10; i < 7490; i++) count[i] += count[i-10];
	for (int i = 25; i < 7490; i++) count[i] += count[i-25];
	for (int i = 50; i < 7490; i++) count[i] += count[i-50];
	while (scanf("%d", &n) != EOF) {
		printf("%d\n", count[n]);
	}
	return 0;
}