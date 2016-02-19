#include <cstdio>
using namespace std;

int main() {
	int n, val;
	while (scanf("%d", &n) && n != 0) {
		bool output = false;
		while (n--) {
			scanf("%d", &val);
			if (val != 0) {
				if (output) printf(" ");
				printf("%d", val);
				output = true;
			}
		}
		if (!output) printf("0\n");
		else printf("\n");
	}
	return 0;
}