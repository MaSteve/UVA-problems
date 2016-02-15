#include <iostream>
#include <string>
using namespace std;

int proc() {
	string line;
	getline(cin, line);
	if (line == "S") return 1;
	else if (line == "ENDPROGRAM" || line == "END_IF" || line == "ELSE") return -1;
	else if (line == "IF") {
		int paths1 = 1, paths2 = 1, p = 1;
		while (p != -1) {
			paths1 *= p;
			p = proc(i+1);
		}
		p = 1; 
		while (p != -1) {
			paths2 *= p;
			p = proc(i+1);
		}
		return paths1 + paths2;
	}
	return -1;
}

int main() {
	int N;
	string trash;
	cin >> N;
	getline(cin, trash);
	while (N--) {
		int paths = 1, p = 1;
		while (p != -1) {
			paths *= p;
			p = proc();
		}
		cout << paths << endl;
	}
	return 0;
}