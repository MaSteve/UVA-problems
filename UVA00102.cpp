#include <iostream>
#include <string>
using namespace std;

int main() {
	int B[3], G[3], C[3], p[6];
	string s[6] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};
	while (cin >> B[0] >> G[0] >> C[0] >> B[1] >> G[1] >> C[1] >> B[2] >> G[2] >> C[2]) {
		p[0] = G[0] + C[0] + B[1] + G[1] + B[2] + C[2];
		p[1] = G[0] + C[0] + B[1] + C[1] + B[2] + G[2];
		p[2] = G[0] + B[0] + G[1] + C[1] + B[2] + C[2];
		p[3] = G[0] + B[0] + B[1] + C[1] + C[2] + G[2];
		p[4] = B[0] + C[0] + G[1] + C[1] + B[2] + G[2];
		p[5] = B[0] + C[0] + B[1] + G[1] + C[2] + G[2];
		int min = 0;
		for (int i = 1; i < 6; i++) if (p[i]<p[min]) min = i;
		cout << s[min] << " " << p[min] << endl;
	}
}