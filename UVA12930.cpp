#include <iostream>
using namespace std;

int main() {
    string n1, n2;
    int c = 1;
    while (cin >> n1 >> n2) {
        int i = 0;
        int comp = 0;
        for (; i < n1.length() && i < n2.length(); i++) {
            if (n1[i] == '.' && n1[i] != n2[i]) { comp = -1; break; }
            if (n2[i] == '.' && n1[i] != n2[i]) { comp = 1; break; }
            if (n1[i] < n2[i] && !comp) comp = -1;
            else if (n1[i] > n2[i] && !comp) comp = 1;
        }
        for (; i < n1.length() && !comp; i++) {
            if (n1[i] != '0') comp = 1;
        }
        for (; i < n2.length() && !comp; i++) {
            if (n2[i] != '0') comp = -1;
        }
        printf("Case %d: ", c);
        if (comp == -1) printf("Smaller\n");
        else if (comp == 0) printf("Same\n");
        else printf("Bigger\n");
        c++;
    }
    return 0;
}
