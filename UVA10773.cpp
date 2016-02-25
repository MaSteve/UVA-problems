#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		double t, t1, t2, d, u, v;
		scanf("%lf %lf %lf", &d, &v, &u);
		bool ok = (u > v) && (u != 0) && (v != 0);
		if (ok) {
			t1 = d/u;
			t2 = d/sqrt(u*u - v*v);
			t = fabs(t1-t2);
		}
		printf("Case %d: ", i);
		if (ok) printf("%.3lf\n", t);
		else printf("can't determine\n");
	}
	return 0;
}