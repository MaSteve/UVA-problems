#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, string> is;

int main() {
    int T;
    cin >> T;
    vector<string> st, st2;
    vector<is> res;
    unordered_map<string, int> m;
    while (T--) {
        int n;
        cin >> n;
        st.clear();
        st2.clear();
        m.clear();
        res.clear();
        string s;
        getline(cin, s);
        for (int i = 0; i < n; i++) {
            getline(cin, s);
            st.push_back(s);
        }
        for (int i = 0; i < n; i++) {
            getline(cin, s);
            m[s] = i;
            st2.push_back(s);
        }
        for (int i = n - 1, j = n - 1; i >= 0 && j >= 0; i--) {
            for (; j >= 0; j--) {
                if (st2[i] == st[j]) break;
                else res.push_back(is(m[st[j]], st[j]));
            }
            j--;
        }
        sort(res.begin(), res.end());
        for (int i = res.size()-1; i >= 0; i--) {
            printf("%s\n", res[i].second.c_str());
        }
        printf("\n");
    }
    return 0;
}
