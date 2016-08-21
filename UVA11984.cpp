#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		double C, d;
		cin >> C >> d;
		C += (d*5)/9;
		printf("Case %d: %.2f\n", i, C);
	}
	return 0;
}