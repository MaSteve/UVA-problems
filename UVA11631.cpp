#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;

struct ufds {
	vi p, r;
	int numSets;
	ufds(int N) {
		p.assign(N, 0); r.assign(N, 0); numSets = N;
		for (int i = 0; i < N; i++) p[i] = i;
	}
	int findSet(int i) {
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}
	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j) {
		int x = findSet(i), y = findSet(j);
		if (x != y) {
			if (r[x] > r[y]) p[y] = x;
			else {
				p[x] = y;
				if (r[x] == r[y]) r[y]++;
			}
			numSets--;
		}
	}
};

int main() {
	int m, n;
	priority_queue<iii> q;
	while (scanf("%d %d", &m, &n) && !(m == 0 && n == 0)) {
		ufds u(m+1);
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			q.push(iii(-z, ii(x, y)));
			sum += z;
		}
		while (!q.empty()) {
			if(!u.isSameSet(q.top().second.first, q.top().second.second)) {
				sum += q.top().first;
				u.unionSet(q.top().second.first, q.top().second.second);
			}
			q.pop();
		}
		printf("%d\n", sum);
	}
	return 0;
}