#include <cstdio>
using namespace std;

int main() {
	int s1, s2;
	while (scanf("%d %d", &s1, &s2) && !(s1 == 0 && s2 == 0)) {
		int count = 0, carrie = 0;
		while (s1 != 0 || s2 != 0) {
			int sum = s1%10 + s2%10 + carrie;
			if (sum >= 10) carrie = 1, count++;
			else carrie = 0;
			s1 /= 10;
			s2 /= 10;
		}
		if (count > 1) printf("%d carry operations.\n", count);
		else if (count == 1) printf("1 carry operation.\n");
		else printf("No carry operation.\n");
	}
	return 0;
}