#include <cstdio>
#include <stack>
using namespace std;

int main() {
	stack<int> s;
	int n;
	while (scanf("%d", &n) && n != 0) {
		int m, cont = 0, pos;
		bool ok;
		while (scanf("%d", &m) && m != 0) {
			if (cont == 0) {
				ok = true;
				pos = 1;
				while (!s.empty()) s.pop();
			}
			if (ok){
				if (s.empty()) s.push(pos), pos++;
				while (s.top() != m && pos <= n) {
					s.push(pos);
					pos++;
				}
				if (s.top() == m) s.pop();
				else ok = false;
			}
			cont++;
			if (cont == n) {
				if (ok) printf("Yes\n");
				else printf("No\n");
				cont = 0;
			}
		}
		printf("\n");
	}
	return 0;
}