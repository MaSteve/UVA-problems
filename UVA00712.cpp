#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    int c = 1;
    while (cin >> n && n != 0) {
        vector<int> var;
        for (int i = 0; i < n; i++) {
            char c;
            int val;
            cin >> c >> val;
            var.push_back(val);
        }
        string dist;
        cin >> dist;
        int m;
        cin >> m;
        printf("S-Tree #%d:\n", c++);
        for (int i = 0; i < m; i++) {
            string path;
            cin >> path;
            int pos = 0;
            for (int i = 0; i < n; i++) {
                pos <<= 1;
                pos += path[i] == '1'? 1: 0;
            }
            printf("%c", dist[pos]);
        }
        printf("\n\n");
    }
    return 0;
}
