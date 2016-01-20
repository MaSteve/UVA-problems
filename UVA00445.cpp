#include <cstdio>
#include <cctype>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	char c;
	int r = 0;
	while (scanf("%c", &c) != EOF) {
		if (isdigit(c)) {
			r += c - '0'; 
			continue;
		} else if (c == '!' || c == '\n') printf("\n");
		else if (c == 'b') c = ' ';
		for (;r > 0; r--) printf("%c", c);
	}
	return 0;
}