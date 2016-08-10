#include <iostream>
#include <algorithm>
using namespace std;

int proc(int player, int a, int b) {
	if (a % b == 0) return player;
	int i = a/b;
	while (i > 0) {
		if (proc(1-player, max(a-(b*i), b), min(a-(b*i), b)) == player) return player;
		i--;
	}
	return 1 - player;
}

int main() {
	int a, b;
	while (cin >> a >> b && !(a == 0 && b == 0)) {
		if (proc(0, max(a, b), min(a, b))) printf("Ollie wins\n");
		else printf("Stan wins\n");
	}
	return 0;
}