#include <iostream>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        char c1, c2, c3, c4;
        int val;
        scanf("%c%c%c%c%c%d", &c4, &c1, &c2, &c3, &c4, &val);
        val = ((c1-'A')*676 + (c2-'A')*26 + (c3-'A')) - val;
        if (val <= 100 && val >= -100) printf("nice\n");
        else printf("not nice\n");
    }
    return 0;
}
