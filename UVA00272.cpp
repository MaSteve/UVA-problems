#include <cstdio>
using namespace std;

int main() {
	char c;
	bool open = false;
	while (scanf("%c", &c) != EOF) {
		if (c == '"') {
			if (open) printf("''");
			else printf("``");
			open = !open;
		} else printf("%c", c);
	}
	return 0;
}