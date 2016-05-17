#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> vi;
vector<vi> AdjList;
bool visited[26];

void toposort(int j) {
    for (int i = 0; i < AdjList[j].size(); i++) {
        if (!visited[AdjList[j][i]]) {
            visited[AdjList[j][i]] = true;
            toposort(AdjList[j][i]);
        }
    }
    printf("%c", j+'A');
}

int main() {
    string n;
    vector<string> v;
    while (cin >> n && n != "#") {
        v.push_back(n);
    }

    for (int i = 0; i < 26; i++) visited[i] = true;
    AdjList.assign(26, vi());
    for (int i = 0; i < v.size()-1; i++) {
        for (int j = 0; j < v[i].length() && j < v[i+1].length(); j++) {
            if (v[i][j] != v[i+1][j]) {
                AdjList[v[i+1][j]-'A'].push_back(v[i][j] - 'A');
                visited[v[i][j]-'A'] = visited[v[i+1][j]-'A'] = false;
                break;
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        if (!visited[i]) {
            visited[i] = true;
            toposort(i);
        }
    }
    printf("\n");
    return 0;
}
