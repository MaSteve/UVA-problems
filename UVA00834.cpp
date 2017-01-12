#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n, d;
    while (cin >> n >> d) {
        vector<int> v;
        while (d != 0) {
            int bi = n / d;
            v.push_back(bi);
            n -= d*bi;
            int auxi = d;
            d = n, n = auxi;
        }
        printf("[");
        for (int i = 0; i < v.size(); i++) {
            printf("%d", v[i]);
            if (i != v.size() - 1) {
                if (i == 0) printf(";");
                else printf(",");
            }
        }
        printf("]\n");
    }
    return 0;
}
