#include <iostream>
#include <cstdlib>
#include <unordered_map>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, M, auxi;
		unordered_map<int, int> l1, l2;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> auxi;
			l1[auxi]++;
		}
		for (int i = 0; i < M; i++) {
			cin >> auxi;
			l2[auxi]++;
		}
		int count = 0;
		for (auto it = l1.begin(); it != l1.end(); ++it) {
			count += abs(l2[it->first] - it->second);
			it->second = l2[it->first] = min(l2[it->first], it->second);
		}
		for (auto it = l2.begin(); it != l2.end(); ++it) {
			count += abs(l1[it->first] - it->second);
			it->second = l1[it->first] = min(l1[it->first], it->second);
		}
		printf("%d\n", count);
	}
	return 0;
}