#include <cstdio>
#include <cctype>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	char c;
	vector<pair<int, int> > v;
	v.assign(30, pair<int, int>(0, 0));
	for (int i = 0; i < 30; i++) v[i].second = i;
	while (scanf("%c", &c) != EOF)
		if (isalpha(c)) {
			if (isupper(c)) v[c-'A'].first--;
			else v[c-'a'].first--;
		}
	sort(v.begin(), v.end());
	for (int i = 0; i < 30; i++) 
		if (v[i].first < 0) printf("%c %d\n", v[i].second + 'A', -v[i].first);
		else break;
	return 0;
}