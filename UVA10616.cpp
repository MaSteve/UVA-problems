#include <iostream>
#include <unordered_map>
#include <utility>
using namespace std;

typedef pair<int, int> ii;
typedef unordered_map<int, ii> uiii;
typedef unordered_map<int, uiii> uiv;
typedef unordered_map<int, uiv> uv;
typedef unordered_map<int, uv> uvi;

int N;
int val[201];
uvi reg;

int func(int m, int d, int mod, int p) {
    if (reg[m][d][mod][p].second == 1) return reg[m][d][mod][p].first;
    int r = 0;
    if (m != 1) {
        for (int i = p; i <= N - m; i++) {
            r += func(m-1, d, (d+mod-(val[i]%d))%d, i+1);
        }
    } else {
        for (int i = p; i <= N - m; i++) {
            r += ((val[i]%d)+d)%d == mod? 1: 0;
        }
    }
    reg[m][d][mod][p].first = r;
    reg[m][d][mod][p].second = 1;
    return r;
}

int main() {
    int Q, m, d, set = 1;
    while (cin >> N >> Q && !(N == 0 && Q == 0)) {
        reg.clear();
        printf("SET %d:\n", set);
        for (int i = 0; i < N; i++) cin >> val[i];
        for (int i = 1; i <= Q; i++) {
            cin >> d >> m;
            printf("QUERY %d: %d\n", i, func(m, d, 0, 0));
        }
        set++;
    }
    return 0;
}
