#include <cstdio>
#include <bitset>
using namespace std;

int main() {
	bitset<1000010> bs;
	int n, m;
	while (scanf("%d %d", &n, &m) && !(n == 0 && m == 0)) {
		bool ok = true;
		bs.reset();
		for (int i = 0; i < n; i++) {
			int start, end;
			scanf("%d %d", &start, &end);
			if (ok) {
				for (int i = start; i < end && ok; i++) {
					ok = !(bs[i]);
					bs.set(i);
				}
			}
		}
		for (int i = 0; i < m; i++) {
			int start, end, inter, pos;
			scanf("%d %d %d", &start, &end, &inter);
			if (ok) {
				pos = start;
				while (pos <= 1000000 && ok) {
					for (int i = 0; i < end - start && i+pos <= 1000000 && ok; i++) {
						ok = !(bs[i+pos]);
						bs.set(i+pos);
					}
					pos += inter;
				}
			}
		}
		if (ok) printf("NO ");
		printf("CONFLICT\n");
	}
	return 0;
}