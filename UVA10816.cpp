#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <unordered_map>
#include <queue>
using namespace std;

typedef pair<double, double> dd;
typedef pair<int, int> ii;
typedef pair<double, int> di;
typedef pair<int, double> id;
typedef pair<dd, ii> ddii;
typedef vector<ddii> vddii;
typedef vector<id> vid;
typedef vector<double> vd;
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

vector<vid> AdjList;

int N, E;

stack<int> st;
vd dist;

void dijkstra(int s, int Dest){
    dist.assign(N, 1000000000); dist[s]=0;
    vi pred(N, -1);
    priority_queue<di, vector<di>, greater<di> > pq;
    pq.push(di(0,s));
    while(!pq.empty()){
        di front=pq.top(); pq.pop();
        double d=front.first; int u=front.second;
        if (d > dist[u]) continue;
        for(int j=0; j< (int)AdjList[u].size(); j++){
            id v = AdjList[u][j];
            if (dist[u] + v.second < dist[v.first]){
                dist[v.first] = dist[u] + v.second;
                pred[v.first] = u;
                pq.push(di(dist[v.first],v.first));
    }}}
	int i=Dest;
    st.push(Dest);
    while (i != s) {i = pred[i]; st.push(i);}
}

int main() {
    while (cin >> N >> E) {
        int S, T;
        cin >> S >> T;
        S--, T--;
        AdjList.assign(N, vid());
        ds.clear(N);
        priority_queue<ddii> pq;
        for (int i = 0; i < E; i++) {
            int X, Y;
            double R, D;
            cin >> X >> Y >> R >> D;
            ddii val = make_pair(make_pair(-R, -D), make_pair(X-1, Y-1));
            pq.push(val);
        }
        double maxTemp = -100;
        while (!pq.empty()) {
            if (ds.isSameSet(S, T) && -pq.top().first.first != maxTemp) break;
            ds.unionSet(pq.top().second.first, pq.top().second.second);
            maxTemp = - pq.top().first.first;
            AdjList[pq.top().second.first].push_back(make_pair(pq.top().second.second, -pq.top().first.second));
            AdjList[pq.top().second.second].push_back(make_pair(pq.top().second.first, -pq.top().first.second));
            pq.pop();
        }
        dijkstra(S, T);
        bool first = false;
        while (!st.empty()) {
            if (first) printf(" ");
            else first = true;
            printf("%d", st.top()+1);
            st.pop();
        }
        printf("\n%.1lf %.1lf\n", dist[T], maxTemp);
    }
    return 0;
}
