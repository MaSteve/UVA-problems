#include <cstdio>
#include <utility>
#include <cmath>
#include <algorithm>
using namespace std;

typedef pair<double, double> ii;

ii islands[1002];

int main() {
	int n, d;
	int cases = 1;
	scanf("%d %d", &n, &d);
	d *= d;
	while (n != 0 && d != 0) {
		int cont = 0;
		bool ok = true;
		for (int i = 0; i < n; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			int sq = d - y*y;
			if (sq < 0) ok = false;
			if (ok) {
				double r = sqrt(sq);
				islands[i].first = x - r;
				islands[i].second = x + r;
			}
		}
		if (ok) {
			sort(islands, islands+n);
			for (int i = 0; i < n; i++) {
				cont ++;
				int j;
				for (j = i + 1; j < n; j++) {
					if (islands[i].second >= islands[j].first) {
						if(islands[i].second >= islands[j].second) i = j;
					}
					else {
						i = j - 1;
						break;
					}
				}
				if(j == n) break;
			}
		}
		else cont = -1;
		printf("Case %d: %d\n", cases, cont);
		scanf("%d %d", &n, &d);
		d *= d;
		cases++;
	}
	return 0;
}