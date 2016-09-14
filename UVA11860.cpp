#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <utility>
using namespace std;

typedef pair<string, int> si;

int main() {
    int T;
    cin >> T;
    string line;
    getline(cin, line);
    for (int c = 1; c <= T; c++) {
        vector<string> text;
        unordered_set<string> words;
        unordered_map<string, int> match;
        while (getline(cin, line) && line != "END") {
            int p = 0, l = 0;
            for (int i = 0; i < line.length(); i++) {
                if (!isalpha(line[i])) {
                    if (l != 0) text.push_back(line.substr(p, l)), words.insert(line.substr(p, l));
                    p = i+1;
                    l = 0;
                } else {
                    l++;
                }
            }
            if (l != 0) text.push_back(line.substr(p, l)), words.insert(line.substr(p, l));
        }
        int ini = 0, end = 999999, count = 0, cini = 0;
        queue<si> q;
        for (int i = 0; i < text.size(); i++) {
            if (match[text[i]] == 0) count++;
            match[text[i]]++;
            q.push(make_pair(text[i], i));
            while (match[q.front().first] > 1) match[q.front().first]--, q.pop(), cini = q.front().second;
            if (count == words.size()) {
                if (i-cini < end-ini) ini = cini, end = i;
            }
        }
        printf("Document %d: %d %d\n", c, ini + 1, end + 1);
    }
    return 0;
}
