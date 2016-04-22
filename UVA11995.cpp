#include <cstdio>
#include <stack>
#include <queue>
using namespace std;

int main() {
	int n;
	stack<int> stack;
	queue<int> queue;
	priority_queue<int> pqueue;
	while (scanf("%d", &n) != EOF) {
		int s, q, pq;
		s = q = pq = 1;
		while (!stack.empty()) stack.pop();
		while (!queue.empty()) queue.pop();
		while (!pqueue.empty()) pqueue.pop();
		while (n--) {
			int op, elem;
			scanf("%d %d", &op, &elem);
			if (op == 1) {
				if (s) stack.push(elem);
				if (q) queue.push(elem);
				if (pq) pqueue.push(elem);
			} else {
				if (stack.empty() || queue.empty() || pqueue.empty()) s = q = pq = 0;
				if (s) s = stack.top() == elem, stack.pop();
				if (q) q = queue.front() == elem, queue.pop();
				if (pq) pq = pqueue.top() == elem, pqueue.pop();
			}
		}
		if (s+q+pq > 1) printf("not sure\n");
		else if (s+q+pq == 1) {
			if (s) printf("stack\n");
			else if (q) printf("queue\n");
			else printf("priority queue\n");
		} else {
			printf("impossible\n");
		}
	}
	return 0;
}