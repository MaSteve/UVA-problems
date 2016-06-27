#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <unordered_set>
#include <sstream>
using namespace std;

bool match(char c) {
    return !isalnum(c) && !isspace(c);
}

char func(char c) {
    if (match(c)) return ' ';
    return c;
}

int main() {
    int K, E, set = 1;
    string s;
    unordered_set<string> l;
    while (cin >> K >> E) {
        l.clear();
        for (int i = 0; i < K; i++) {
            cin >> s;
            l.insert(s);
        }
        int m = 0;
        string output = "";
        getline(cin, s);
        for (int i = 0; i < E; i++) {
            int cont = 0;
            getline(cin, s);
            string aux = s;
            transform(aux.begin(), aux.end(), aux.begin(), ::tolower);
            transform(aux.begin(), aux.end(), aux.begin(), &func);
            //aux.erase(remove_if(aux.begin(), aux.end(), &match), s.end());
            stringstream ss;
            ss << aux;
            while (ss >> aux) {
                if (l.count(aux)) cont++;
            }
            if (cont == m) output += "\n" + s;
            else if (cont > m) output = s, m = cont;
        }
        cout << "Excuse Set #" << set << "\n" << output << endl << endl;
        set++;
    }
    return 0;
}
