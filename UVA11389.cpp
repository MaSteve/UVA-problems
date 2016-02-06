#include <cstdio>
#include <queue>
using namespace std;

int main() {
	int n, d, r;
	priority_queue<int> mq, aq;
	while (scanf("%d %d %d", &n, &d, &r) && !(n == 0 && d == 0 && r == 0)) {
		for (int i = 0; i < n; i++) {
			int m;
			scanf("%d", &m);
			mq.push(-m);
		}
		for (int i = 0; i < n; i++) {
			int m;
			scanf("%d", &m);
			aq.push(m);
		}
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int m = aq.top() - mq.top() - d;
			if(m > 0) sum += m;
			aq.pop(); mq.pop();
		}
		printf("%d\n", sum*r);
	}
	return 0;
}