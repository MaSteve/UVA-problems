#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

int main() {
	int L, G;
	priority_queue<pair<int , int> > q;
	while (scanf("%d %d", &L, &G) && !(L == 0 && G == 0)) {
		for (int i = 0; i < G; i++) {
			int x, r;
			scanf("%d %d", &x, &r);
			pair<int, int> g(-(x-r), -(x+r));
			q.push(g);
		}
		int cont = 0, x = 0;
		bool stop = false;
		while (x < L && !stop) {
			if (q.empty() || x < -q.top().first) stop = true;
			else {
				cont++;
				int ext = -q.top().second;
				while (!q.empty() && x >= -q.top().first) {
					if (-q.top().second > ext) ext = -q.top().second;
					q.pop();
				}
				x = ext;
			}
		}
		while (!q.empty()) q.pop();
		if (stop) printf("-1\n");
		else printf("%d\n", G-cont);
	}
	return 0;
}