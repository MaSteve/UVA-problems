#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

int grid[102][102];
unordered_set<int> s;

int main() {
    int N, c = 1;
    while (cin >> N && N != 0) {
        s.clear();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> grid[i][j];
                grid[i][j]--;
            }
        }
        int N1, N2, N3;
        cin >> N1 >> N2 >> N3;
        N1--, N2--, N3--;
        if (N1 > N2) {
            int auxi = N2;
            N2 = N1;
            N1 = auxi;
        }
        queue<int> q;
        q.push(N1*1000 + N2);
        s.insert(N1*1000 + N2);
        bool ok = false;
        printf("Game #%d\n", c);
        c++;
        while (!q.empty() && !ok) {
            int i1 = (q.front()/1000)%1000, i2 = q.front()%1000, d = q.front()/1000000;
            q.pop();
            if (i1 == N3 || i2 == N3) {
                printf("Minimum Number of Moves = %d\n", d);
                ok = true;
                break;
            }
            int n1 = grid[i1][i2], n2 = grid[i2][i1];
            if (n1 != -1) {
                int r = i2;
                if (n1 > r) {
                    int auxi = r;
                    r = n1;
                    n1 = auxi;
                }
                int val = n1*1000 + r;
                if (!s.count(val)) s.insert(val), val += (d+1)*1000000, q.push(val);
            }
            if (n2 != -1) {
                int r = i1;
                if (n2 < r) {
                    int auxi = r;
                    r = n2;
                    n2 = auxi;
                }
                int val = r*1000 + n2;
                if (!s.count(val)) s.insert(val), val += (d+1)*1000000, q.push(val);
            }
        }
        if (!ok) printf("Destination is Not Reachable !\n");
        printf("\n");
    }
    return 0;
}
