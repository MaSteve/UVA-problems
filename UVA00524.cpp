#include <cstdio>
#include <unordered_set>
using namespace std;

unordered_set<int> primes({2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37});
int sol[16], n;
bool used[17];

void proc(int pos) {
	if(pos == n) {
		if (primes.count(sol[n-1] + sol[0])) {
			bool first = false;
			for (int i = 0; i < n; i++) {
				if (first) printf(" ");
				else first = true;
				printf("%d", sol[i]);
			}
			printf("\n");
		}
	} else {
		for (int i = 2; i <= n; i++) {
			if (!used[i] && primes.count(sol[pos-1] + i)) {
				used[i] = true;
				sol[pos] = i;
				proc(pos+1);
				used[i] = false;
			}
		}
	}
}

int main() {
	int cases = 1;
	sol[0] = 1;
	for (int i = 2; i <= n; i++) {
			used[i] = false;
	}
	bool first = false;
	while (scanf("%d", &n) != EOF) {
		if (first) printf("\n");
		else first = true;
		printf("Case %d:\n", cases++);
		proc(1);
	}
	return 0;
}