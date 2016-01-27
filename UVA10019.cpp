#include <cstdio>
using namespace std;

int bits(int hexDigit) {
	switch(hexDigit) {
		case 0: return 0;
		case 1: return 1;
		case 2: return 1;
		case 3: return 2;
		case 4: return 1;
		case 5: return 2;
		case 6: return 2;
		case 7: return 3;
		case 8: return 1;
		case 9: return 2;
	}
	return 0;
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int M1, M2, b1 = 0, b2 = 0;
		scanf("%d", &M1);
		M2 = M1;
		while (M1 != 0) {
			b1 += M1 % 2;
			M1 = M1 >> 1;
		}
		while (M2 != 0) {
			b2 += bits(M2 % 10);
			M2 /= 10;
		}
		printf("%d %d\n", b1, b2);
	}
	return 0;
}