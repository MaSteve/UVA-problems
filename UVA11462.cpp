#include <cstdio>
using namespace std;

int main() {
	int ages[101];
	for (int i = 0; i < 101; i++) ages[i] = 0;
	int n;
	while (scanf("%d", &n) && n != 0) {
		for (int i = 0; i < n; i++) {
			int age;
			scanf("%d", &age);
			ages[age]++;
		}
		bool first = true;
		for (int i = 0; i < 101; i++)
			for (; ages[i] > 0; ages[i]--) {
				if (!first) printf(" ");
				printf("%d", i);
				first = false;
			}
		printf("\n");
	}
	return 0;
}