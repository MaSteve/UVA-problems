#include <cstdio>
#include <queue>
#include <vector> 
#include <utility>
#include <bitset>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;

struct UFDS {
	vi p;
	void init(int N) {
		p.assign(N, 0);
		for (int i = 0; i < N; i++) p[i]=i;
	}
	int find(int i) {
		return p[i]==i? i: (p[i] = find(p[i])); 
	}
	void unionn(int i, int j) {
		int x = find(i), y = find(j);
		if (x != y) p[y] = x;
	}
};

priority_queue<iii> pq;
UFDS ufds;

int N, M, A, cost, aero;

void proc() {
	int cair = aero, croad = 0;
	while (!pq.empty()) {
		iii road = pq.top();
		pq.pop();
		if (ufds.find(road.second.first) != ufds.find(road.second.second)){
			ufds.unionn(road.second.first, road.second.second);
			cair--;
			croad -= road.first;
			int ncost = cair*A + croad;
			if (ncost<cost) cost = ncost, aero = cair;
		}
	}
}

int main() {
	int cases;
	scanf("%d", &cases);
	for (int i = 1; i <= cases; i++) {
		scanf("%d %d %d", &N, &M, &A);
		aero = N;
		cost = N*A;
		ufds.init(N+2);
		for (int j = 0; j < M; j++){
			int x, y, c;
			scanf("%d %d %d", &x, &y, &c);
			pq.push(iii(-c, ii(x, y)));
		}
		proc();
		printf("Case #%d: %d %d\n", i, cost, aero);
	}
	return 0;
}