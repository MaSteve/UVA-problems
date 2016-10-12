#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;

typedef pair<double, double> dd;
typedef pair<int, int> ii;
typedef pair<double, int> di;
typedef pair<int, double> id;
typedef pair<dd, ii> ddii;
typedef vector<ii> vii;
typedef vector<id> vid;
typedef vector<double> vd;
typedef vector<int> vi;

vector<vii> AdjList1, AdjList2;

int P, Q;

int dijkstra(int s, vector<vii> * AdjList){
    vi dist(P, 1000000000); dist[s]=0;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(0,s));
    while(!pq.empty()){
        ii front=pq.top(); pq.pop();
        int d=front.first, u=front.second;
        if (d > dist[u]) continue;
        for(int j=0; j< (int)(*AdjList)[u].size(); j++){
            ii v = (*AdjList)[u][j];
            if (dist[u] + v.second < dist[v.first]){
                dist[v.first] = dist[u] + v.second;
                pq.push(ii(dist[v.first],v.first));
    }}}
    int ret = 0;
    for (int i = 0; i < dist.size();i++) ret += dist[i];
    return ret;
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        cin >> P >> Q;
        AdjList1.assign(P, vii());
        AdjList2.assign(P, vii());
        for (int i = 0; i < Q; i++) {
            int x, y, d;
            cin >> x >> y >> d;
            AdjList1[x-1].push_back(make_pair(y-1, d));
            AdjList2[y-1].push_back(make_pair(x-1, d));
        }
        int cost = dijkstra(0, &AdjList1) + dijkstra(0, &AdjList2);
        printf("%d\n", cost);
    }
    return 0;
}
