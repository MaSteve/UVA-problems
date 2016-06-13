#include <iostream>
#include <unordered_map>
#include <utility>
#include <queue>
using namespace std;

int main() {
    queue<int> s;
    unordered_map<int, int> m;
    int n;
    while (cin >> n) {
        if (!m[n]) s.push(n);
        m[n]++;
    }
    while (!s.empty()) {
        printf("%d %d\n", s.front(), m[s.front()]);
        s.pop();
    }
    return 0;
}
