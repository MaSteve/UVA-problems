#include <cstdio>
#include <queue>
using namespace std;

priority_queue<long> pq1, pq2;

int main() {
	long n;
	while (scanf("%ld", &n) != EOF) {
		if (pq1.empty() || pq1.top() >= n) pq1.push(n);
		else pq2.push(-n);
		while (pq2.size() > pq1.size()) {
			pq1.push(-pq2.top());
			pq2.pop();
		}
		while (pq1.size() > pq2.size()) {
			pq2.push(-pq1.top());
			pq1.pop();
		}
		if (pq1.size() == pq2.size()) {
			printf("%ld\n", (pq1.top()-pq2.top())/2);
		} else printf("%ld\n", -pq2.top());
	}
}