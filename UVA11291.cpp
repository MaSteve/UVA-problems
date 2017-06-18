#include <iostream>
#include <sstream>
#include <cctype>
using namespace std;

double expected(stringstream & ss) {
    char trash;
    while (!(ss.peek() == '(' || ss.peek() == '-' || isdigit(ss.peek()))) ss.get(trash);
    if (ss.peek() == '(') {
        ss.get(trash);
        double p, e1, e2;
        ss >> p;
        e1 = expected(ss);
        e2 = expected(ss);
        ss >> trash;
        return p*(e1 + e2) + (1 - p)*(e1 - e2);
    } else {
        double d;
        ss >> d;
        return d;
    }
    return 0.0;
}

int main() {
    string s;
    while (getline(cin, s) && s != "()") {
        stringstream ss(s);
        double e = expected(ss);
        printf("%.2lf\n", e);
    }
    return 0;
}
