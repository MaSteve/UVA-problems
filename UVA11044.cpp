#include <cstdio>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int n, m;
		scanf("%d %d", &n, &m);
		printf("%d\n", (((n-2)/3)+((n-2)%3==0?0:1))*(((m-2)/3)+((m-2)%3==0?0:1)));
	}
	return 0;
}