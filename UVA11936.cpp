#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a < b + c && b < a + c && c < a + b && a > 0 && b > 0 && c > 0) printf("OK\n");
        else printf("Wrong!!\n");
    }
    return 0;
}
