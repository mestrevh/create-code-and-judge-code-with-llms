/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool isLeap(long long y){
    return (y%400==0) || (y%4==0 && y%100!=0);
}

static long long daysFromCivil(long long y, long long m, long long d){
    static int mdays[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    y -= m <= 2;
    long long era = (y >= 0 ? y : y-399) / 400;
    unsigned yoe = (unsigned)(y - era * 400);
    unsigned doy = (unsigned)((m > 2 ? m - 3 : m + 9) * 30 + d - 1);
    unsigned doe = yoe * 365 + yoe/4 - yoe/100 + doy;
    return era * 146097 + (long long)doe - 719468;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long d1,m1,y1,d2,m2,y2;
    if(!(cin >> d1 >> m1 >> y1)) return 0;
    cin >> d2 >> m2 >> y2;

    long long a = daysFromCivil(y1,m1,d1);
    long long b = daysFromCivil(y2,m2,d2);

    cout << (b - a) << "\n";
    return 0;
}