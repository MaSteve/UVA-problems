#include <iostream>
#include <ctime>
using namespace std;

string sign(int day, int mon) {
    switch (mon) {
        case 0: return (day <= 20? "capricorn": "aquarius");
        case 1: return (day <= 19? "aquarius": "pisces");
        case 2: return (day <= 20? "pisces": "aries");
        case 3: return (day <= 20? "aries": "taurus");
        case 4: return (day <= 21? "taurus": "gemini");
        case 5: return (day <= 21? "gemini": "cancer");
        case 6: return (day <= 22? "cancer": "leo");
        case 7: return (day <= 21? "leo": "virgo");
        case 8: return (day <= 23? "virgo": "libra");
        case 9: return (day <= 23? "libra": "scorpio");
        case 10: return (day <= 22? "scorpio": "sagittarius");
        case 11: return (day <= 22? "sagittarius": "capricorn");
    }
    return "";
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int date;
        struct tm t = {0};
        cin >> date;
        t.tm_year = date%10000 - 1900;
        t.tm_mday = (date/10000)%100;
        t.tm_mon = (date/1000000) - 1;
        mktime(&t);
        t.tm_mday += 280;
        mktime(&t);
        printf("%d %.2d/%.2d/%.2d %s\n", i, t.tm_mon + 1, t.tm_mday, t.tm_year + 1900, sign(t.tm_mday, t.tm_mon).c_str());
    }
    return 0;
}
