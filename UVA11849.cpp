#include <cstdio>
#include <unordered_set>
using namespace std;

int main() {
	int N, M;
	unordered_set<int> cds;
	while (scanf("%d %d", &N, &M) && !(N == 0 && M == 0)) {
		cds.clear();
		while (N--) {
			int cd;
			scanf("%d", &cd);
			cds.insert(cd);
		}
		int count = 0;
		while (M--) {
			int cd;
			scanf("%d", &cd);
			if (cds.count(cd)) count ++;
		}
		printf("%d\n", count);
	}
	return 0;
}