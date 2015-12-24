#include <cstdio>
using namespace std;

int main() {
	int cases;
	scanf("%d", &cases);
	for (int i = 0; i < cases; i++) {
		int sum = 0;
		for (int j = 0; j < 16; j++){
			int n;
			scanf("%1d", &n);
			if (j % 2 == 0) sum += n == 9? n: (n*2)%9;
			else sum += n;
		}
		if (sum % 10 != 0) printf("Invalid\n");
		else printf("Valid\n");
	}
	return 0;
}