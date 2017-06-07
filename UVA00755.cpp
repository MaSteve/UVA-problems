#include <iostream>
#include <unordered_map>
#include <set>
#include <cctype>
using namespace std;

unordered_map<int, int> dir;
set<int> repeated;

int proc(char c) {
    switch (c) {
        case 'A':
        case 'B':
        case 'C': return 2;
        case 'D':
        case 'E':
        case 'F': return 3;
        case 'G':
        case 'H':
        case 'I': return 4;
        case 'J':
        case 'K':
        case 'L': return 5;
        case 'M':
        case 'N':
        case 'O': return 6;
        case 'P':
        case 'R':
        case 'S': return 7;
        case 'T':
        case 'U':
        case 'V': return 8;
        case 'W':
        case 'X':
        case 'Y': return 9;
    }
    return 0;
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        dir.clear();
        repeated.clear();
        int M;
        cin >> M;
        while (M--) {
            string s;
            cin >> s;
            int val = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == '-') continue;
                val *= 10;
                if (isalpha(s[i])) val += proc(s[i]);
                else val += s[i] - '0';
            }
            dir[val]++;
            if (dir[val] > 1) repeated.insert(val);
        }
        if (repeated.empty()) printf("No duplicates.\n");
        else {
            for (auto it = repeated.begin(); it != repeated.end(); ++it) {
                printf("%03d-%04d %d\n", (*it)/10000, (*it)%10000, dir[*it]);
            }
        }
        if (N) printf("\n");
    }
    return 0;
}
