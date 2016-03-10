#include <cstdio>
using namespace std;

int proc(int n) {
	return (((n+1)*n)/2) - ((((n/2)+1)*(n/2))/2)*2;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b;
		scanf("%d", &a);
		scanf("%d", &b);
		int sum = proc(b)-proc(a) + (a%2)*a;
		printf("Case %d: %d\n", i, sum);
	}
	return 0;
}