#include <cstdio>
#include <queue>
using namespace std;

int main() {
	queue<int> q;
	int n;
	while (scanf("%d", &n) && n != 0) {
		for (int i = 1; i <= n; i++) q.push(i);
		printf("Discarded cards:");
		bool first = false;
		while (q.size() > 1) {
			if (first) printf(", ");
			else first = true, printf(" ");
			printf("%d", q.front());
			q.pop();
			q.push(q.front()); q.pop();
		}
		printf("\nRemaining card: %d\n", q.front());
		q.pop();
	}
	return 0;
}