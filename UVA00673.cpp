#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    while (n--) {
        getline(cin, s);
        stack<char> st;
        bool ok = true;
        for (int i = 0; i < s.length() && ok; i++) {
            if (s[i] == '(' || s[i] == '[') st.push(s[i]);
            else {
                if (!st.empty() && ((s[i] == ')' && st.top() == '(') || (s[i] == ']' && st.top() == '[')))
                    st.pop();
                else ok = false;
            }
        }
        ok = ok && st.empty();
        if (ok) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
