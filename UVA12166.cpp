#include <iostream>
#include <cctype>
#include <sstream>
#include <unordered_map>
using namespace std;

int main() {
    int N;
    unordered_map<long long, int> m;
    cin >> N;
    string s;
    getline(cin, s);
    while (N--) {
        m.clear();
        getline(cin, s);
        istringstream iss(s);
        char c;
        long long val;
        int open = 0, max = -1, id = -1, nodes = 0;
        while (iss) {
            c = iss.peek();
            if (isdigit(c)) {
                nodes++;
                iss >> val;
                m[val*(1<<open)]++;
                if (m[val*(1<<open)] > max) max = m[val*(1<<open)], id = val*(1<<open);
                continue;
            } else if (c == '[') open++;
            else if (c == ']') open--;
            iss >> c;
        }
        printf("%d\n", nodes-max);
    }
    return 0;
}
