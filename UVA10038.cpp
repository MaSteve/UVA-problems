#include <iostream>
#include <unordered_set>
#include <cmath>
using namespace std;

int main() {
	unordered_set<int> set;
	int n;
	while (cin >> n) {
		bool jolly = true;
		int previous;
		cin >> previous;
		if (n != 1) {
			set.clear();
			for (int i = 1; i < n; i++) {
				int item;
				cin >> item;
				set.insert(abs(item-previous));
				previous = item;
			}
			for (int i = 1; i < n; i++) {
				if(!set.count(i)) { jolly = false; break; } 
			}
		}
		if(jolly) cout << "Jolly" << endl;
		else cout << "Not jolly" << endl;
	}
	return 0;
}