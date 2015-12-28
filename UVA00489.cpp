#include <cstdio>
#include <cctype>
using namespace std;

int counts[30];

int main() {
	int r;
	while (scanf("%d", &r) && r != -1) {
		printf("Round %d\n", r);
		for (int i = 0; i < 30; i++) counts[i] = 0;
		char c;
		int chars = 0, strikes = 0;
		scanf("%c", &c);
		while(scanf("%c", &c) && isalpha(c)) {
			chars++;
			counts[c-'a']++;
		}
		bool win = false;
		while(scanf("%c", &c) && isalpha(c)) {
			if (counts[c-'a'] == 0) strikes++;
			else if (counts[c-'a'] != -1) chars -= counts[c-'a'];
			counts[c-'a'] = -1;
			if (strikes < 7 && chars == 0) win = true;
		}
		if (win) printf("You win.\n");
		else if (strikes >= 7) printf("You lose.\n");
		else printf("You chickened out.\n");
	}
	return 0;
}