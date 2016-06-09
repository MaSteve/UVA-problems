#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

struct ufds {
    vii p; vi r; int numSets;
    ufds(int N) {
        p.assign(N, ii(0, 1)); r.assign(N, 0); numSets = N;
        for (int i = 0; i < N; i++) p[i].first = i;
    }
    int subSetSize(int i) {
        int x = findSet(i);
        return p[x].second;
    }
    int findSet(int i) { return (p[i].first==i)? i: (p[i].first=findSet(p[i].first)); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j) {
        int x = findSet(i), y = findSet(j);
        if (x != y) {
            if (r[x] > r[y]) p[y].first = x, p[x].second += p[y].second;
            else {
                p[x].first = y;
                p[y].second += p[x].second;
                if (r[x] == r[y]) r[y]++;
            } numSets--;
        }
    }
};

int main() {
    int N;
    cin >> N;
    while (N--) {
        int F;
        unordered_map<string, int> names;
        cin >> F;
        ufds friends(2*F);
        while (F--) {
            string s1, s2;
            cin >> s1 >> s2;
            if (!names.count(s1)) names.insert(make_pair(s1, names.size()));
            if (!names.count(s2)) names.insert(make_pair(s2, names.size()));
            friends.unionSet(names[s1], names[s2]);
            printf("%d\n", friends.subSetSize(names[s1]));
        }
    }
    return 0;
}
