#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <utility>
using namespace std;

typedef pair<string, int> si;
typedef vector<string> vs;
typedef unordered_map<string, vs> svs;

int proc(string s1, string s2, svs & graph) {
    unordered_set<string> match;
    queue<si> q;
    q.push(make_pair(s1, 0));
    match.insert(s1);
    while (!q.empty()) {
        if (q.front().first != s2) {
            for (int i = 0; i < graph[q.front().first].size(); i++) {
                if (!match.count(graph[q.front().first][i])) q.push(make_pair(graph[q.front().first][i], q.front().second + 1)), match.insert(graph[q.front().first][i]);
            }
        } else return q.front().second;
        q.pop();
    }
    return 0;
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        unordered_set<string> dic;
        svs graph;
        string s;
        while (cin >> s && s != "*") {
            for (auto it = dic.begin(); it != dic.end(); ++it) {
                string auxi = *it;
                if (auxi.length() == s.length()) {
                    int dist = 0;
                    for (int i = 0; i < auxi.length() && dist < 2; i++) {
                        if (auxi[i] != s[i]) dist++;
                    }
                    if (dist == 1) graph[s].push_back(auxi), graph[auxi].push_back(s);
                }
            }
            dic.insert(s);
        }
        string line;
        getline(cin, line);
        while (getline(cin, line) && line != "") {
            int i = 0;
            for (; i < line.length() && line[i] != ' '; i++);
            string s1 = line.substr(0, i), s2 = line.substr(i+1, line.length()-i-1);
            printf("%s %d\n", line.c_str(), proc(s1, s2, graph));
        }
        if (N) printf("\n");
    }
    return 0;
}
