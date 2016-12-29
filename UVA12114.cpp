#include <iostream>
using namespace std;

int main() {
    int B, S, c = 1;
    while (cin >> B >> S && !(B == 0 && S == 0)) {
        printf("Case %d: ", c);
        if (B == 1) printf(":-\\\n");
        else if (S >= B) printf(":-|\n");
        else printf(":-(\n");
        c++;
    }
    return 0;
}
