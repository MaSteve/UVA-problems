#include <cstdio>
#include <string>
#include <cctype>
using namespace std;

void value(int n, int & i, int & v, int & x, int & l, int & c) {
	if (n == 100) {
		c += 1; 
		return;
	}
	switch(n%10) {
		case 9: i += 1, x += 1; break;
		case 8: i += 3, v += 1; break;
		case 7: i += 2, v += 1; break;
		case 6: i += 1, v += 1; break;
		case 5: v += 1; break;
		case 4: i += 1, v += 1; break;
		case 3: i += 3; break;
		case 2: i += 2; break;
		case 1: i += 1; break;
	}
	switch(n/10) {
		case 9: x += 1, c += 1; break;
		case 8: x += 3, l += 1; break;
		case 7: x += 2, l += 1; break;
		case 6: x += 1, l += 1; break;
		case 5: l += 1; break;
		case 4: x += 1, l += 1; break;
		case 3: x += 3; break;
		case 2: x += 2; break;
		case 1: x += 1; break;
	}
}

int main() {
	int number;
	while (scanf("%d", &number) && number != 0) {
		int i, v, x, l, c;
		i = v = x = l = c = 0;
		for (int j = 1; j <= number; j++) value(j, i, v, x, l, c);
		printf("%d: %d i, %d v, %d x, %d l, %d c\n", number, i, v, x, l, c);
	}
	return 0;
}