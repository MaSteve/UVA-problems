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
	int n, m;
	priority_queue<iii> q;
	queue<int> output;
	while (scanf("%d %d", &n, &m) && !(m == 0 && n == 0)) {
		ufds u(n+1);
		for (int i = 0; i < m; i++) {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			q.push(iii(-z, ii(x, y)));
		}
		while (!q.empty()) {
			if(!u.isSameSet(q.top().second.first, q.top().second.second)) {
				u.unionSet(q.top().second.first, q.top().second.second);
			} else {
				output.push(-q.top().first);
			}
			q.pop();
		}
		if (output.empty()) printf("forest\n");
		else {
			bool first = false;
			while (!output.empty()) {
				if (first) printf(" ");
				else first = true;
				printf("%d", output.front());
				output.pop();
			}
			printf("\n");
		}
	}
	return 0;
}