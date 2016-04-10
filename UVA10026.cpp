#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

bool op(iii p1, iii p2) {
	return p1.first.second*p2.first.first > p2.first.second*p1.first.first;
}

int main() {
	int cases;
	vector<iii> v;
	scanf("%d", &cases);
	bool first2 = false;
	while (cases--) {
		v.clear();
		if (first2) printf("\n");
		else first2 = true;
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			int f, s;
			scanf("%d %d", &f, &s);
			v.push_back(iii(ii(f, s), i));
		}
		stable_sort(v.begin(), v.end(), op);
		bool first = false;
		for (int i = 0; i < v.size(); i++) {
			if (first) printf(" ");
			else first = true;
			printf("%d", v[i].second + 1);
		}
		printf("\n");
	}
	return 0;
}