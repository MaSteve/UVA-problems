#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <utility>
#include <cctype>
using namespace std;

int main() {
	unordered_map<long long, int> fib;
	long long fib0 = 0, fib1 = 1;
	int pos = 1;
	for (int i = 0; i < 91; i++, pos++) {
		long long aux = fib1 + fib0;
		fib.insert(pair<long long, int>(aux, pos));
		fib0 = fib1;
		fib1 = aux;
	}
	int T;
	queue<long long> seq;
	cin >> T;
	while (T--) {
		int N;
		long long max = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			long long f;
			cin >> f;
			seq.push(f);
			if (f > max) max = f;
		}
		string cypher;
		getline(cin, cypher);
		getline(cin, cypher);
		string msg(fib[max], ' ');
		int i = 0;
		while (!seq.empty()) {
			for (; i < cypher.length() && !isupper(cypher[i]); i++);
			msg[fib[seq.front()]-1] = cypher[i];
			seq.pop();
			i++;
		}
		cout << msg << endl;
	}
	return 0;
}