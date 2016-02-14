#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>
using namespace std;

int main() {
	unordered_map<int, vector<int> > graph;
	int cases;
	cin >> cases;
	for (int i = 1; i <= cases; i++) {
		graph.clear();
		string line;
		cin >> line;
		int pos = 0, max = 1, min = -1;
		char last = 'C';
		bool first = true;
		for (int j = 0; j < line.length(); j++) {
			if (!graph.count(pos)) graph.insert(pair<int, vector<int> >(pos, vector<int>()));
			if (line[j] == 'R') {
				if (last == 'F') pos++;
				graph[pos].push_back(j);
				pos++;
			} else if (line[j] == 'F') {
				if (last == 'R' || (last == 'C' && !first)) pos--;
				graph[pos].push_back(j);
				pos--;
			} else {
				if (last == 'F') pos++;
				graph[pos].push_back(j);
			}
			last = line[j];
			if (pos > max) max = pos;
			if (pos < min) min = pos;
			first = false;
		}
		printf("Case #%d:\n", i);
		for (int j = max; j >= min; j--) {
			if (graph[j].empty()) continue;
			int size = graph[j].back()+1; 
			string row(size+2, ' ');
			row[0] = '|';
			for (int k = 0; k < graph[j].size(); k++) {
				int c = graph[j][k];
				row[c + 2] = line[c] == 'R'? '/': line[c] == 'C'? '_': '\\';
			}
			cout << row << endl;
		}
		cout << "+";
		for(int j = 0; j <= line.length()+1; j++) cout << "-";
		printf("\n\n");
	}
	return 0;
}