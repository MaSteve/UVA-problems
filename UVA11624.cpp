#include <iostream>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

int mat[1001][1001];
bool mask[1001][1001];
bool mask2[1001][1001];
int R, C;
int jx, jy;

inline bool limits(int x, int y) {
    return x < R && x >= 0 && y < C && y >= 0;
}

inline bool border(int x, int y) {
    return x == R-1 || x == 0 || y == C-1 || y == 0;
}

queue<iii> fire;

void flood() {
    while (!fire.empty()) {
        iii sq = fire.front();
        fire.pop();
        if (limits(sq.first.first, sq.first.second) && !mask2[sq.first.first][sq.first.second]) {
            mask2[sq.first.first][sq.first.second] = true;
            mat[sq.first.first][sq.first.second] = sq.second;
            fire.push(iii(ii(sq.first.first + 1, sq.first.second), sq.second + 1));
            fire.push(iii(ii(sq.first.first - 1, sq.first.second), sq.second + 1));
            fire.push(iii(ii(sq.first.first, sq.first.second + 1), sq.second + 1));
            fire.push(iii(ii(sq.first.first, sq.first.second - 1), sq.second + 1));
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> R >> C;
        bool ok = false;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                char c;
                cin >> c;
                if (c == '#') {
                    mat[i][j] = -1;
                    mask[i][j] = mask2[i][j] = true;
                }
                else {
                    mat[i][j] = 1000000;
                    if (c == 'J') jx = i, jy = j;
                    if (c == 'F') fire.push(iii(ii(i, j), 0));
                    mask[i][j] = mask2[i][j] = false;
                }
            }

        }
        flood();
        queue<iii> q;
        q.push(iii(ii(jx, jy), 0));
        ok = false;
        int sol;
        while (!q.empty() && !ok) {
            iii sq = q.front();
            q.pop();
            if (limits(sq.first.first, sq.first.second) && sq.second < mat[sq.first.first][sq.first.second]) {
                if (border(sq.first.first, sq.first.second)) ok = true, sol = sq.second;
                else if (!mask[sq.first.first][sq.first.second]) {
                    mask[sq.first.first][sq.first.second] = true;
                    q.push(iii(ii(sq.first.first + 1, sq.first.second), sq.second + 1));
                    q.push(iii(ii(sq.first.first - 1, sq.first.second), sq.second + 1));
                    q.push(iii(ii(sq.first.first, sq.first.second + 1), sq.second + 1));
                    q.push(iii(ii(sq.first.first, sq.first.second - 1), sq.second + 1));
                }
            }
        }
        if (ok) printf("%d\n", sol + 1);
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}
