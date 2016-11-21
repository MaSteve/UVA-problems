#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, int> m;
    for (int i = 1; i <= 100000; i++) {
        int val = i, auxi = i;
        while (auxi) {
            val += auxi%10;
            auxi /= 10;
        }
        if (!m[val]) m[val] = i;
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        printf("%d\n", m[n]);
    }
    return 0;
}
