#include <iostream>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

unordered_map<int, int> m;

int hell(int i) {
    if (i == 0) return 1;
    if (m[i] == 0) {
        double s = sin(i);
        m[i] = (hell(floor(i-sqrt(i))) + hell(floor(log(i))) + hell(floor(i*s*s)))%1000000;
    }
    return m[i];
}

int main() {
    int n;
    while (cin >> n && n != -1) {
        printf("%d\n", hell(n));
    }
    return 0;
}
