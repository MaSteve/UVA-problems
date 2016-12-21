#include <iostream>
using namespace std;

int ptime(string t) {
    char * ts = &t[0];
    ts[2] = ts[5] = ts[8] = 0;
    return atoi(ts)*3600 + atoi(ts + 3)*60 + atoi(ts + 6);
}

int penergy(int score) {
    if (score == 0) return 6;
    int res = 0;
    while (score) {
        switch (score%10) {
            case 0: res += 6; break;
            case 1: res += 2; break;
            case 2: res += 5; break;
            case 3: res += 5; break;
            case 4: res += 4; break;
            case 5: res += 5; break;
            case 6: res += 6; break;
            case 7: res += 3; break;
            case 8: res += 7; break;
            case 9: res += 6; break;
        }
        score /= 10;
    }
    return res;
}

int main() {
    string s, t, team;
    int scoreH, scoreV, score, ct, energy, c = 0;
    while (cin >> s >> t) {
        if (s == "START") {
            c++;
            scoreH = scoreV = energy = 0;
            ct = ptime(t);
        } else {
            int at = ptime(t);
            energy += (penergy(scoreH) + penergy(scoreV))*(at-ct);
            ct = at;
            if (s == "SCORE") {
                cin >> team >> score;
                if (team == "home") scoreH += score;
                else scoreV += score;
            } else printf("Case %d: %d\n", c, energy);
        }
    }
    return 0;
}
