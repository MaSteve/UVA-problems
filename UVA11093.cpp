#include <iostream>
using namespace std;

int p[100010];
int q[100010];

int main() {
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        int N;
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> p[i];
        for (int i = 0; i < N; i++)
            cin >> q[i];
        int count = 0, prev = -1, l = 0;
        bool check = true;
        for (int i = 0; i < N; i++) {
            count += p[i] - q[i];
            if (count < 0) {
                if (!check) count -= l;
                check = true;
            }
            if (check && p[i] - q[i] >= 0) {
                l = (p[i] - q[i]) - count;
                count = p[i] - q[i];
                check = false;
                prev = i;
            }
        }
        if (check || l > count) printf("Case %d: Not possible\n", c);
        else printf("Case %d: Possible from station %d\n", c, prev + 1);
    }
    return 0;
}
