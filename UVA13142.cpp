#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    while (N--) {
        double T, S, D;
        cin >> T >> S >> D;
        T *= 54; D *= 625;
        double val = (D/T);
        if (int(floor(val)) > 0) printf("Remove %d tons\n", int(floor(val)));
        else printf("Add %d tons\n", int(floor(fabs(val))));
    }
    return 0;
}
