#include <iostream>
#include <utility>
#include <string>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef pair<string, ii> sii; 

int main() {
	int T;
	vector<sii> v;
	cin >> T;
	while (T--) {
		v.clear();
		int D;
		cin >> D;
		while (D--) {
			sii tm("", ii(0,0));
			cin >> tm.first >> tm.second.first >> tm.second.second;
			v.push_back(tm);
		}
		cin >> D;
		while (D--) {
			int price;
			string tm;
			cin >> price;
			int count = 0;
			for (int i = 0; i < v.size() && count < 2; i++) {
				if (v[i].second.first <= price && price <= v[i].second.second) {
					count++;
					tm = v[i].first;
				}
			}
			if (count == 1) cout << tm << endl;
			else cout << "UNDETERMINED" << endl;
		}
		if (T != 0) cout << endl;
	}
	return 0;
}