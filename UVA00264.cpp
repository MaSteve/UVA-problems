#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

void proc(int lim, int & a, int & b) {
	int f = (-1 + floor(sqrt(1+8*lim)))/2;
	int g = ((f+1)*f)/2;
	if (g == lim) {
		if (f%2 == 0) a = f, b = 1;
		else b = f, a = 1;
	}
	else {
		int dif = lim - g;
		if ((f+1)%2 == 0) a = dif , b = f+2-dif;
		else b = dif , a = f+2-dif;
	}
}

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		int a, b;
		proc(n, a, b);
		printf("TERM %d IS %d/%d\n", n, a, b);
	}
	return 0;
}