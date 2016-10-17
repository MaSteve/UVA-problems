#include <iostream>
#include <utility>
using namespace std;

typedef pair<int, int> ii;

int main() {
    int N;
    while (cin >> N && N != 0) {
        ii last = ii(0, 0), first, second, p, v1 = ii(0, 0), v2;
        int p1 = 0, p2 = 0;
        bool ok = true;
        for (int i = 0; i < N; i++) {
            cin >> p.first >> p.second;
            if (!ok) continue;
            if (!i) first = p, last = p;
            if (i == 1) second = p;
            v2 = ii(p.first - last.first, p.second - last.second);
            p2 = (v1.first * v2.second) - (v1.second * v2.first);
            ok = ((p1 <= 0 && p2 <= 0) || (p1 >= 0 && p2 >= 0));
            p1 = p2;
            v1 = v2;
            last = p;
        }
        if (ok) { // We must repeat the process with the first and the second point.
            p = first;
            v2 = ii(p.first - last.first, p.second - last.second);
            p2 = (v1.first * v2.second) - (v1.second * v2.first);
            ok = ((p1 <= 0 && p2 <= 0) || (p1 >= 0 && p2 >= 0));
            p1 = p2;
            v1 = v2;
            last = p;
        }
        if (ok) {
            p = second;
            v2 = ii(p.first - last.first, p.second - last.second);
            p2 = (v1.first * v2.second) - (v1.second * v2.first);
            ok = ((p1 <= 0 && p2 <= 0) || (p1 >= 0 && p2 >= 0));
        }
        if (ok) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
