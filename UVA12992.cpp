#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int N;
        cin >> N;
        printf("Case #%d: %d\n", i, 2*(N-1)+1);
    }
    return 0;
}
