#include <iostream>
#include <set>
#include <utility>
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, string> iis;

set<iis> st;

inline int proc(string s) {
    int ret = 0;
    for (int i = 0; i < s.length(); i++) {
        for (int j = i + 1; j < s.length(); j++) {
            if (s[i] > s[j]) ret++;
        }
    }
    return ret;
}

int main() {
    int M;
    cin >> M;
    while (M--) {
        int n, m;
        cin >> n >> m;
        st.clear();
        for (int i = 0; i < m; i++) {
            string s;
            cin >> s;
            st.insert(iis(ii(proc(s), i), s));
        }
        for (auto it = st.begin(); it != st.end(); ++it) {
            printf("%s\n", it->second.c_str());
        }
        if (M) printf("\n");
    }
    return 0;
}
