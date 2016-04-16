#include <cstdio>
#include <queue>
using namespace std;

int main() {
	priority_queue<long long> pq;
	int N;
	while (scanf("%d", &N) && N != 0) {
		while (N--) {
			long long m;
			scanf("%lld", &m);
			pq.push(-m);
		}
		long long cost = 0;
		while (pq.size() > 1) {
			long long sum = pq.top(); pq.pop();
			sum += pq.top(); pq.pop();
			cost -= sum;
			pq.push(sum);
		}
		pq.pop();
		printf("%lld\n", cost);
	}
	return 0;
}