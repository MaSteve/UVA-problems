#include <iostream>

using namespace std;

int main(){
	int mag, yel, cyan;
	int T;
	cin >> T;
	while (T--) {
		cin >> mag >> yel >> cyan;
		string s;
		cin >> s;
		bool ok = true;
		for (int i = 0; i < s.length() && ok; i++) {
			if (s[i] == 'M') mag --;
			else if (s[i] == 'Y') yel --;
			else if (s[i] == 'C') cyan --;
			else if (s[i] == 'R') mag --, yel--;
			else if (s[i] == 'B') mag--, yel--, cyan--;
			else if (s[i] == 'G') yel--, cyan--;
			else if (s[i] == 'V') cyan--, mag--;
			else if (s[i] == 'W');
			ok = (mag >= 0 && yel >= 0 && cyan >= 0);
		}
		if (ok){
			printf("YES %d %d %d\n", mag, yel, cyan);
		} else printf("NO\n");
	}
	return 0;
}
