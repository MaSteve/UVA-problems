#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int main() {
	string trash;
	priority_queue<iii> pq;
	int k;
	while (cin >> trash && trash != "#") {
		int q, p;
		cin >> q >> p;
		pq.push(iii(-p, ii(-q, -p)));
	}
	cin >> k;
	while (k--) {
		iii ins = pq.top();
		pq.pop();
		cout << -ins.second.first << endl;
		ins.first += ins.second.second;
		pq.push(ins);
	}
	return 0;
}