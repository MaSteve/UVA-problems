#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <utility>
using namespace std;

int main() {
	unordered_map<char, int> prices;
	int N;
	cin >> N;
	while (N--) {
		prices.clear();
		int K;
		cin >> K;
		while (K--) {
			char c;
			int price;
			cin >> c >> price;
			prices.insert(pair<char, int>(c, price));
		}
		int M, cost = 0;
		cin >> M;
		string s;
		getline(cin, s);
		while (M--) {
			getline(cin, s);
			for (int i = 0; i < s.length(); i++) {
				if (prices.count(s[i])) cost += prices[s[i]];
			}
		}
		printf("%d.%02d$\n", cost/100, cost%100);
	}
}