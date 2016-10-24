#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <unordered_map>
#include <queue>
using namespace std;

typedef vector<int> vi;

struct ufds {
    vi p, r; int numSets;
    void clear(int N) {
        p.assign(N, 0); r.assign(N, 0); numSets = N;
        for (int i = 0; i < N; i++) p[i] = i;
    }
    int findSet(int i) { return (p[i]==i)? i: (p[i]=findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j) {
        int x = findSet(i), y = findSet(j);
        if (x != y) {
            if (r[x] > r[y]) p[y] = x;
            else {
                p[x] = y;
                if (r[x] == r[y]) r[y]++;
            } numSets--;
        }
    }
};

ufds ds;

vector<vi> AdjList;
unordered_map<string, int> m;

int main() {
    int P, R, c = 1, visited[51];
    while (cin >> P >> R && !(P == 0 && R == 0)) {
        AdjList.assign(P, vi());
        ds.clear(P);
        m.clear();
        int count = 0;
        for (int i = 0; i < R; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            if (!m.count(s1)) m[s1] = count, count++;
            if (!m.count(s2)) m[s2] = count, count++;
            AdjList[m[s1]].push_back(m[s2]);
            AdjList[m[s2]].push_back(m[s1]);
            ds.unionSet(m[s1], m[s2]);
        }
        printf("Network %d: ", c);
        if (ds.numSets > 1) printf("DISCONNECTED\n\n");
        else {
            int maxi = 0;
            for (int i = 0; i < P; i++) {
                for (int j = 0; j < P; j++) visited[j] = 0;
                queue<int> q;
                q.push(i);
                visited[i] = 1;
                while (!q.empty()) {
                    int u = q.front()%100, d = q.front()/100; q.pop();
                    if (d > maxi) maxi = d;
                    for (int j = 0; j < AdjList[u].size(); j++) {
                        if (!visited[AdjList[u][j]]) q.push(AdjList[u][j] + (d+1)*100), visited[AdjList[u][j]] = 1;
                    }
                }
            }
            printf("%d\n\n", maxi);
        }
        c++;
    }
    return 0;
}
