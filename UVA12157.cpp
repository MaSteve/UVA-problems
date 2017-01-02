#include <iostream>
using namespace std;

int main() {
    int T, N;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        cin >> N;
        int mile = 0, juice = 0;
        for (int i = 0; i < N; i++) {
            int call;
            cin >> call;
            mile += (call/30 + 1)*10;
            juice += (call/60 + 1)*15;
        }
        printf("Case %d: ", c);
        int mini = min(mile, juice);
        if (mile == mini) printf("Mile ");
        if (juice == mini) printf("Juice ");
        printf("%d\n", mini);
    }
    return 0;
}
