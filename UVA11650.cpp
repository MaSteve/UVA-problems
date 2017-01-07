#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int h, m;
        char c;
        cin >> h >> c >> m;
        h = 12 - h;
        if (h == 0) h = 12;
        m = 60 - m;
        if (m == 60) m = 0;
        if (m != 0) h--;
        if (h == 0) h = 12;
        printf("%02d:%02d\n", h, m);
    }
    return 0;
}
