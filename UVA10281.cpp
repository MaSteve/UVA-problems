#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
    double time = 0, speed = 0, dist = 0;
    string line;
    while (getline(cin, line)) {
        double stamp = 60*(60*(line[0]*10 + line[1]) + line[3]*10 + line[4]) + line[6]*10 + line[7];
        if (line.length() > 8) {
            dist += (stamp-time)*speed;
            time = stamp;
            double aux = 0;
            for (int i = 9; i < line.length(); i++) aux *= 10, aux += line[i]-'0';
            speed = aux/3600;
        } else {
            printf("%s %.2f km\n", line.substr(0, 8).c_str(), dist + (stamp-time)*speed);
        }
    }
    return 0;
}
