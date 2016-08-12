#include <iostream>
#include <algorithm>
using namespace std;

int avaible[6];

int proc(int player, int points) {
	if (points > 31) return player;
	int i = 5;
	bool ret = false;
	while (i >= 0) {
		if(avaible[i]) {
			avaible[i]--;
			ret = proc(1-player, points + i + 1) == player;
			avaible[i]++;
			if (ret) return player;
		}
		i--;
	}
	return 1 - player;
}

int main() {
	string s;
	while (cin >> s) {
		int points = 0;
		for (int i = 0; i < 6; i++) avaible[i] = 4;
		for (int i = 0; i < s.length(); i++) avaible[s[i]-'1']--, points += s[i]-'0';
		cout << s << " ";
		if (proc(s.length()%2, points)) cout << "B\n";
		else cout << "A\n";
	}
	return 0;
}