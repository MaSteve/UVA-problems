#include <iostream>
using namespace std;

int main() {
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        if (N % 3 != 1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
