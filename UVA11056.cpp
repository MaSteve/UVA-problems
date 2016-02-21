#include <iostream>
#include <string>
#include <queue>
#include <cctype>
using namespace std;

struct pilot{
	string name, upper;
	int min, sec, ms;
	bool operator<(const pilot & rhs) const {
		if (min > rhs.min) return true;
		else if (min < rhs.min) return false;
		else {
			if (sec > rhs.sec) return true;
			else if (sec < rhs.sec) return false;
			else {
				if (ms > rhs.ms) return true;
				else if (ms < rhs.ms) return false;
				else {
					return upper > rhs.upper;
				}
			}
		}
		return false;
	}
};

int main() {
	int N;
	priority_queue<pilot> grid;
	while (cin >> N) {
		while (N--) {
			pilot p;
			string trash;
			cin >> p.name >> trash >> p.min >> trash >> p.sec >> trash >> p.ms >> trash;
			p.upper = p.name;
			for (int i=0; i < p.upper.length(); i++) p.upper[i] = toupper(p.upper[i]);
			grid.push(p);
		}
		int row = 1;
		while (!grid.empty()) {
			cout << "Row " << row << endl;
			cout << grid.top().name << endl;
			grid.pop();
			if (!grid.empty()) {
				cout << grid.top().name << endl;
				grid.pop();
			}
			row++;
		}
		cout << endl;
	}
	return 0;
}