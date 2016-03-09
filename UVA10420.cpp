#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	map<string, int> m;
	string name, trash;
	int N;
	cin >> N;
	while (N--) {
		cin >> name;
		getline(cin, trash);
		if (!m.count(name)) m.insert(pair<string, int>(name, 0));
		m[name]++;
	}
	for (auto it = m.begin(); it != m.end(); ++it) {
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}