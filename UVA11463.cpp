#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vii> AdjList;

void dijkstra(int s, vi & dist) {
    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(0,s));
    while(!pq.empty()){
        ii front=pq.top(); pq.pop();
        int d=front.first, u=front.second;
        if (d > dist[u]) continue;
        for(int j=0; j< (int)AdjList[u].size(); j++){
            ii v = AdjList[u][j];
            if (dist[u] + v.second < dist[v.first]){
                dist[v.first] = dist[u] + v.second;
                pq.push(ii(dist[v.first],v.first));
}}}}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int N, R;
        cin >> N >> R;
        AdjList.assign(N, vii());
        while (R--) {
            int u, v;
            cin >> u >> v;
            AdjList[u].push_back(make_pair(v, 1));
            AdjList[v].push_back(make_pair(u, 1));
        }
        int s, d;
        cin >> s >> d;
        vi d1(N, INT_MAX), d2(N, INT_MAX);
        dijkstra(s, d1); dijkstra(d, d2);
        int time = 0;
        for (int j = 0; j < N; j++) {
            if (d1[j] + d2[j] > time) time = d1[j] + d2[j];
        }
        printf("Case %d: %d\n", i, time);
    }
    return 0;
}
