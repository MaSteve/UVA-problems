#include <iostream>
#include <cmath>
#include <unordered_map>
#include <utility>
#include <climits>
using namespace std;

unordered_map<int, int> m;

int proc(int N) {
    if (m[N] == 0 && N != 0) {
        int auxi = floor(sqrt(N));
        int mini = INT_MAX;
        do {
            int val = proc(N - (auxi*auxi)) + 1;
            if (val < mini) mini = val;
            auxi--;
        } while (auxi);
        m[N] = mini;
    }
    return m[N];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        printf("%d\n", proc(N));
    }
    return 0;
}
