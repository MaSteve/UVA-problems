#include <cstdio>
#include <queue>
#include <stack>
#include <cstdlib>
using namespace std;

int main() {
	int B, S, cases = 1;
	priority_queue<int> bach, spin;
	stack<int> pending;
	while (scanf("%d %d", &B, &S) && !(B == 0 && S == 0)) {
		while(!pending.empty()) pending.pop();
		while(!bach.empty()) bach.pop();
		while(!spin.empty()) spin.pop();
		for (int i = 0; i < B; i++) {
			int age;
			scanf("%d", &age);
			bach.push(age);
		}
		for (int i = 0; i < S; i++) {
			int age;
			scanf("%d", &age);
			spin.push(age);
		}
		bool singles = false;
		int bage, count;
		while (!bach.empty()) {
			bage = bach.top();
			bach.pop();
			if (!singles) {
				if (pending.empty() && !spin.empty()) {
					pending.push(spin.top());
					spin.pop();
				}
				while (!spin.empty() && abs(bage - spin.top()) < abs(bage - pending.top())) {
					pending.push(spin.top());
					spin.pop();
				}
				if (!pending.empty()) pending.pop();
				else singles = true, count = bach.size() + 1;
			}
		}
		printf("Case %d: ", cases);
		if (singles) printf("%d %d\n", count, bage);
		else printf("0\n");
		cases ++;
	}
	return 0;
}