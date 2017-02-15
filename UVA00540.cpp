#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int main() {
    queue<int> teams[1001];
    unordered_map<int, int> members;
    queue<int> q;
    int t, c = 1;
    while (cin >> t && t) {
        queue<int> teams[1001];
        queue<int> q;
        members.clear();
        for (int i = 0; i < t; i++) {
            int n;
            cin >> n;
            for (int j = 0; j < n; j++) {
                int var;
                cin >> var;
                members[var] = i;
            }
        }
        printf("Scenario #%d\n", c++);
        string cmd;
        while (cin >> cmd) {
            if (cmd == "STOP") break;
            if (cmd == "DEQUEUE") {
                int team = q.front();
                printf("%d\n", teams[team].front());
                teams[team].pop();
                if (teams[team].size() == 0) q.pop();
            } else if (cmd == "ENQUEUE") {
                int var;
                cin >> var;
                int team = members[var];
                teams[team].push(var);
                if (teams[team].size() == 1) q.push(team);
            }
        }
        printf("\n");
    }
    return 0;
}
