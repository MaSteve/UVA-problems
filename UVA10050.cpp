#include <cstdio>
#include <unordered_set>
using namespace std;

int main() {
	unordered_set<int> set;
	int cases;
	scanf("%d", &cases);
	for (int i = 0; i < cases; i++) {
		set.clear();
		int N, P;
		scanf("%d", &N); scanf("%d", &P);
		for (int j = 0; j < P; j++) {
			int hartal;
			scanf("%d", &hartal);
			for (int m = hartal; m <= N; m+=hartal) if(m % 7 != 0 && m % 7 != 6) set.insert(m);
		}
		printf("%d\n", set.size());
	}
	return 0;
}