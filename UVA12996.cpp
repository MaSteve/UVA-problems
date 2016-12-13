#include <iostream>
using namespace std;

int main() {
    int T;
    int plate[10];
    cin >> T;
    for (int c = 1; c <= T; c++) {
        int N, L;
        cin >> N >> L;
        for (int i = 0; i < N; i++) cin >> plate[i];
        bool ok = true;
        int sum = 0;
        for (int i = 0; i < N; i++) {
            int auxi;
            cin >> auxi;
            ok &= (auxi >= plate[i]);
            sum += plate[i];
        }
        ok &= (sum <= L);
        printf("Case %d: ", c);
        if (ok) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
