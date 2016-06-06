#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

struct ufds {
    vi p, r; int numSets;
    ufds(int N) {
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

int main() {
    int N;
    cin >> N;
    int s;
    bool first = true;
    while (N--) {
        ufds* net;
        char t;
        int n1, n2, suc = 0, unsuc = 0;
        if (first) cin >> s, first = false;
        net = new ufds(s);
        string aux;
        while (cin >> aux) {
            if (aux.length() != 1 || (aux[0]-'0' >= 0 && aux[0]-'0' <= 9)) {
                s = atoi(aux.c_str());
                break;
            }
            cin >> n1 >> n2;
            if (aux[0] == 'c') {
                net->unionSet(n1-1, n2-1);
            } else if (aux[0] == 'q'){
                if (net->isSameSet(n1-1, n2-1)) suc++;
                else unsuc++;
            }
        }
        printf("%d,%d\n", suc, unsuc);
        if (N) printf("\n");
        delete net;
    }
    return 0;
}
