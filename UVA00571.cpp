#include <iostream>
#include <queue>
#include <utility>
#include <stack>
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

int Ca, Cb, N, it = 1;

iii DP[1010][1010];
int DPV[1010][1010];

int proc() {
    queue<ii> q;
    q.push(ii(0, 0));
    DP[0][0] = iii(ii(-1, -1), -1);
    DPV[0][0] = it;
    while (!q.empty()) {
        ii p = q.front();
        q.pop();
        DPV[p.first][p.second] = it;
        if (p.second == N) return p.first;
        if (DPV[Ca][p.second] != it) {
            q.push(ii(Ca, p.second));
            DP[Ca][p.second] = iii(ii(p.first, p.second), 0);
            DPV[Ca][p.second] = it;
        }
        if (DPV[p.first][Cb] != it) {
            q.push(ii(p.first, Cb));
            DP[p.first][Cb] = iii(ii(p.first, p.second), 1);
            DPV[p.first][Cb] = it;
        }
        if (DPV[0][p.second] != it) {
            q.push(ii(0, p.second));
            DP[0][p.second] = iii(ii(p.first, p.second), 2);
            DPV[0][p.second] = it;
        }
        if (DPV[p.first][0] != it) {
            q.push(ii(p.first, 0));
            DP[p.first][0] = iii(ii(p.first, p.second), 3);
            DPV[p.first][0] = it;
        }
        int pa = 0, pb = p.first + p.second;
        if (pb > Cb) pa = pb - Cb, pb = Cb;
        if (DPV[pa][pb] != it) {
            q.push(ii(pa,pb));
            DP[pa][pb] = iii(ii(p.first, p.second), 4);
            DPV[pa][pb] = it;
        }
        pa = p.first + p.second, pb = 0;
        if (pa > Ca) pb = pa - Ca, pa = Ca;
        if (DPV[pa][pb] != it) {
            q.push(ii(pa,pb));
            DP[pa][pb] = iii(ii(p.first, p.second), 5);
            DPV[pa][pb] = it;
        }
    }
    return -1;
}

int main() {
    stack<int> s;
    while (cin >> Ca >> Cb >> N) {
        int sol = proc();
        iii var = DP[sol][N];
        while (var.second != -1) {
            s.push(var.second);
            var = DP[var.first.first][var.first.second];
        }
        while (!s.empty()) {
            switch (s.top()) {
                case 0:
                    printf("fill A\n"); break;
                case 1:
                    printf("fill B\n"); break;
                case 2:
                    printf("empty A\n"); break;
                case 3:
                    printf("empty B\n"); break;
                case 4:
                    printf("pour A B\n"); break;
                case 5:
                    printf("pour B A\n"); break;
            }
            s.pop();
        }
        printf("success\n");
        it++;
    }
    return 0;
}
