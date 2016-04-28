#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int n, p;
int longs[20];

bool proc(int pos, int sum) {
	if (sum == n) return true;
	if (sum < n && pos < p && sum + (p-pos)*longs[pos] >= n) {
		return proc(pos+1, sum + longs[pos]) || proc(pos+1, sum);
	}
	return false;
}

int main() {
	int cases;
	scanf("%d", &cases);
	while (cases--) {
		scanf("%d", &n);
		scanf("%d", &p);
		for (int i = 0; i < p; i++) {
			scanf("%d", &longs[i]);
		}
		sort(longs, longs + p, greater<int>());
		if (proc(0, 0)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}