#include <iostream>
#include <cstdio>
#include <map>
#include <utility>
using namespace std;

int main() {
	int n;
	cin >> n;
	map<string, float> m;
	string tree;
	getline(cin, tree);
	getline(cin, tree);
	while (n--) { 
		m.clear();
		int count = 0;
		while (getline(cin, tree) && tree != "") {
			if (!m.count(tree)) m.insert(pair<string, float>(tree, 0));
			m[tree]++;
			count++;
		}
		for (auto it = m.begin(); it != m.end(); ++it) {
			printf("%s %.4f\n", it->first.c_str(), (it->second*100)/count);
		}
		if (n != 0) printf("\n");
	}
	return 0;
}