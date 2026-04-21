/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool isLeap(int y){
    return (y%400==0) || (y%4==0 && y%100!=0);
}

static int daysInMonth(int y, int m){
    static int mdays[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(m==2) return mdays[m-1] + (isLeap(y) ? 1 : 0);
    return mdays[m-1];
}

static long long daysFromCivil(int y, int m, int d){
    y -= m <= 2;
    long long era = (y >= 0 ? y : y-399) / 400;
    unsigned yoe = (unsigned)(y - era * 400);
    unsigned doy = (unsigned)((153*(m + (m>2?-3:9)) + 2)/5 + d-1);
    unsigned doe = yoe*365 + yoe/4 - yoe/100 + doy;
    return era*146097LL + (long long)doe - 719468LL;
}

static void civilFromDays(long long z, int &y, int &m, int &d){
    z += 719468LL;
    long long era = (z >= 0 ? z : z - 146096LL) / 146097LL;
    unsigned doe = (unsigned)(z - era * 146097LL);
    unsigned yoe = (doe - doe/1460 + doe/36524 - doe/146096) / 365;
    y = (int)(yoe) + (int)era * 400;
    unsigned doy = doe - (365*yoe + yoe/4 - yoe/100);
    unsigned mp = (5*doy + 2)/153;
    d = (int)(doy - (153*mp + 2)/5 + 1);
    m = (int)(mp + (mp < 10 ? 3 : -9));
    y += (m <= 2);
}

static void parseDate(const string& s, int &d, int &m, int &y){
    int dd=0, mm=0, yy=0;
    char c1, c2;
    stringstream ss(s);
    ss >> dd >> c1 >> mm >> c2 >> yy;
    d=dd; m=mm; y=yy;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string aStr, bStr;
    if(!(cin >> aStr)) return 0;
    cin >> bStr;

    int da, ma, ya, db, mb, yb;
    parseDate(aStr, da, ma, ya);
    parseDate(bStr, db, mb, yb);

    long long A = daysFromCivil(ya, ma, da);
    long long B = daysFromCivil(yb, mb, db);

    long long sum = A + B;
    long long midZ2 = sum; 
    bool half = ( (B - A) % 2 != 0 );
    long long midDayZ = sum/2;

    int y, m, d;
    civilFromDays(midDayZ, y, m, d);

    cout << setfill('0') << setw(2) << d << "/" << setw(2) << m << "/" << setw(4) << y << " ";
    if(half) cout << "12:00\n";
    else cout << "00:00\n";
    return 0;
}