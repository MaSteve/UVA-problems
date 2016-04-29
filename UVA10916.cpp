#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int n[23];

void prep() {
	long long fact = 1, acum = 0, expo = 0, pot = 1, i = 2;
	while (expo < 23) {
		fact *= i;
		while (fact % 2 == 0 || fact >= INT_MAX) { //Prevent overflow
			fact >>= 1;
			acum++;
		}
		int bits = acum + ceil(log2(fact));
		if (bits > pot) {
			n[expo] = i - 1;
			expo++;
			pot *= 2;
		}
		i++;
	}
	n[2]--;
}

int main() {
	int y;
	prep();
	while (scanf("%d", &y) && y != 0) {
		printf("%d\n", n[(y/10) - 194]);
	}
	return 0;
}