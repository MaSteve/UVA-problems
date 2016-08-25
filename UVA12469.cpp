#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <utility>
using namespace std;

unordered_map<int, int> map;
unordered_map<int, int> mini;

int proc(int player, int n, int k) {
	if (n <= k) return player;
	if (map[n] == 0) map[n] = 2000000000;
	if (map[n] <= k) return player;
	else if (k <= mini[n]) return 1 - player;
	int i = min(n/3, k);
	mini[n] = max(i, mini[n]);
	while (i > 0) {
		if (proc(1-player, n-i, 2*i) == player) {
			map[n] = i;
			mini[n] = 0; 
			return player;
		}
		i--;
	}
	return 1 - player;
}

int main() {
	int n;
	while (cin >> n && n != 0) {
		if (proc(0, n, n-1)) printf("Roberto\n");
		else printf("Alicia\n");
	}
	return 0;
}