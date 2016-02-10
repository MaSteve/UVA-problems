#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;

int main() {
	int n;
	string msg;
	unordered_map<string, int> freq;
	while (cin >> n >> msg) {
		freq.clear();
		int max = 0;
		string pass = "";
		for (int ini = 0; ini + n <= msg.length(); ini++) {
			string sub = msg.substr(ini, n);
			if (!freq.count(sub)) freq.insert(pair<string, int>(sub, 0));
			freq[sub]++;
			if (freq[sub] > max) max = freq[sub], pass = sub;
		}
		cout << pass << endl;
	}
	return 0;
}