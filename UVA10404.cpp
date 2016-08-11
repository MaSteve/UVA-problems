#include <iostream>
#include <bitset>
using namespace std;

int main() {
	int n, moves[10];
	bitset<1000004> bs;
	while (cin >> n) {
		int m;
		cin >> m;
		bs.reset();
		for (int i = 0; i < m; i++) cin >> moves[i], bs.set(moves[i]);
		for (int i = 1; i <= n; i++) 
			for (int j = 0; j < m && !bs[i]; j++)
				if (i+moves[j] <= n) bs.set(i+moves[j]);
		if (bs[n]) printf("Stan wins\n");
		else printf("Ollie wins\n");
	}
	return 0;
}