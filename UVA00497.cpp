#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int N;
    cin >> N;
    string s;
    getline(cin, s);
    getline(cin, s);
    vector<int> v;
    while (N--) {
        v.clear();
        while (getline(cin, s) && s != "") v.push_back(atoi(s.c_str()));
        vector<int> tam(v.size(), 1), prev(v.size(), -1);
        int best = 0;
        for (int i = 1; i < v.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (v[j] < v[i] && tam[j] + 1 > tam[i])
                    prev[i] = j, tam[i] = tam[j] + 1;
            }
            if (tam[best] < tam[i]) best = i;
        }
        printf("Max hits: %d\n", tam[best]);
        stack<int> st;
        do {
            st.push(v[best]);
            best = prev[best];
        } while (best != -1);
        while (!st.empty()) {
            printf("%d\n", st.top());
            st.pop();
        }
        if (N) printf("\n");
    }
    return 0;
}
