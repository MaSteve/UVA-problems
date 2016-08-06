#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double r, n, pi = 2*acos(0);
	while (cin >> r >> n) {
		double a = n * sin(2*pi / n) * r * r * 0.5;
		printf("%.3f\n", a);
	}
	return 0;
}