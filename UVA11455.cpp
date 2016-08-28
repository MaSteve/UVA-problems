#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, l[4];
    cin >> N;
    while (N--) {
        cin >> l[0] >> l[1] >> l[2] >> l[3];
        sort(l, l+4);
        if (l[0] == l[1] && l[1] == l[2] && l[2] == l[3]) printf("square\n");
        else if (l[0] == l[1] && l[2] == l[3] && l[1] != l[2]) printf("rectangle\n");
        else if (l[3] >= l[0] + l[1] + l[2] ||
             l[3] < (l[0] < l[1] + l[2]? 0 : l[0] - l[1] - l[2])) printf("banana\n");
        else printf("quadrangle\n");
    }
    return 0;
}
