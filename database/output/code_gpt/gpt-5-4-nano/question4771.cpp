/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool isLeap(int y){
    if(y%400==0) return true;
    if(y%100==0) return false;
    return y%4==0;
}

static int daysInMonth(int y, int m){
    static int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(m==2) return d[m] + (isLeap(y)?1:0);
    return d[m];
}

static void addDaysTime(long long &dateDays, int addDays){
    dateDays += addDays;
}

static long long daysFromCivil(int y, int m, int d){
    y -= m <= 2;
    const int era = (y >= 0 ? y : y-399) / 400;
    const unsigned yoe = static_cast<unsigned>(y - era * 400);
    const unsigned doy = (153*(m + (m > 2 ? -3 : 9)) + 2)/5 + d - 1;
    const unsigned doe = yoe * 365 + yoe/4 - yoe/100 + doy;
    return static_cast<long long>(era) * 146097LL + static_cast<long long>(doe) - 719468LL;
}

static void civilFromDays(long long z, int &y, int &m, int &d){
    z += 719468LL;
    const long long era = (z >= 0 ? z : z - 146096) / 146097;
    const unsigned doe = static_cast<unsigned>(z - era * 146097);
    const unsigned yoe = (doe - doe/1460 + doe/36524 - doe/146096) / 365;
    const int y_temp = static_cast<int>(yoe) + static_cast<int>(era) * 400;
    const unsigned doy = doe - (365*yoe + yoe/4 - yoe/100);
    const unsigned mp = (5*doy + 2)/153;
    const unsigned d_temp = doy - (153*mp + 2)/5 + 1;
    const unsigned m_temp = mp + (mp < 10 ? 3 : -9);
    y = y_temp + (m_temp <= 2);
    m = static_cast<int>(m_temp);
    d = static_cast<int>(d_temp);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long d, m, y;
    long long h, mi;
    long long dh, dmi;

    if(!(cin >> d >> m >> y)) return 0;
    cin >> h >> mi;
    cin >> dh >> dmi;

    long long curDays = daysFromCivil((int)y, (int)m, (int)d);
    long long curSeconds = h*3600LL + mi*60LL;
    long long addSeconds = dh*3600LL + dmi*60LL;

    long long totalSeconds = curSeconds + addSeconds;
    long long addDays = totalSeconds / 86400LL;
    long long remSeconds = totalSeconds % 86400LL;

    if(remSeconds < 0){
        remSeconds += 86400LL;
        addDays -= 1;
    }

    long long targetDays = curDays + addDays;
    int ty, tm, td;
    civilFromDays(targetDays, ty, tm, td);

    int th = (int)(remSeconds / 3600LL);
    int tmin = (int)((remSeconds % 3600LL) / 60LL);

    long long diffDays = targetDays - curDays;

    cout << setw(2) << setfill('0') << td << "/"
         << setw(2) << setfill('0') << tm << "/"
         << setw(4) << setfill('0') << ty << "\n";

    cout << setw(2) << setfill('0') << th << ":"
         << setw(2) << setfill('0') << tmin << "\n";

    cout << "Falta " << diffDays << " dias até a data que o Esquisito falou\n";
    return 0;
}