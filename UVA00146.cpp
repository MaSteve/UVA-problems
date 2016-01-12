#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	string str;
	while (cin >> str && str != "#") {
		int pos = -1, last = str.length() - 1;
		for (int i = str.length() - 2; i >= 0; i--) {
			if(str[i] < str[last]) {
				pos = i;
				break;
			}
			else if (str[i] > str[last]) last = i;
		}
		if (pos == -1) cout << "No Successor" << endl;
		else {
			int end = str.length() - 1;
			for (; str[pos] >= str[end]; end--);
			char c = str[end];
			str[end] = str[pos];
			str[pos] = c;
			auto it = str.begin();
			for(int i = 0; i <= pos; i++, ++it);
			sort(it, str.end());
			cout << str << endl;
		}
	}
	return 0;
}