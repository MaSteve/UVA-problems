#include <iostream>
using namespace std;

//long long wine[100010];

int main() {
    int n;
    while (cin >> n && n != 0) {
        /*for (int i = 0; i < n; i++) {
            cin >> wine[i];
        }
        long long acum = 0;
        for (int i = 0; i < n - 1; i++) {
            wine[i+1] += wine[i];
            acum += abs(wine[i]);
        }*/
        long long acum = 0;
        long long wine;
        cin >> wine;
        for (int i = 1; i < n; i++) {
            acum += abs(wine);
            long long auxi;
            cin >> auxi;
            wine += auxi;
        }
        printf("%lld\n", acum);
    }
    return 0;
}
