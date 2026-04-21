/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    getline(cin, s1);
    if(s1.empty()) return 0;
    if(!s1.empty() && s1.back()=='\r') s1.pop_back();

    size_t dash = s1.find('-');
    string firstPart = s1.substr(0, dash);
    string secondPart = (dash==string::npos) ? "" : s1.substr(dash+1);
    auto trim = [](string x){
        size_t a=0;
        while(a<x.size() && isspace((unsigned char)x[a])) a++;
        size_t b=x.size();
        while(b>a && isspace((unsigned char)x[b-1])) b--;
        return x.substr(a,b-a);
    };
    firstPart = trim(firstPart);
    secondPart = trim(secondPart);

    auto parseDate = [](const string& ds)->pair<int,int>{
        string t=trim(ds);
        int d=stoi(t.substr(0,2));
        int m=stoi(t.substr(3,2));
        return {d,m};
    };

    auto [d0, m0] = parseDate(firstPart);
    auto [dToday, mToday] = parseDate(secondPart);

    int T;
    if(!(cin >> T)) return 0;
    double lat0, lon0;
    cin >> lat0 >> lon0;

    auto dateToDay = [](int d, int m)->int{
        return (m-1)*30 + (d-1);
    };
    auto dayToDate = [](int day)->pair<int,int>{
        int m = day/30 + 1;
        int d = day%30 + 1;
        return {d,m};
    };

    int dayFirst = dateToDay(d0, m0);
    int dayToday = dateToDay(dToday, mToday);

    int n = dayToday - dayFirst;
    if(n < 0) n = 0;

    int k = (n / T) + 1;

    int dayNext = dayFirst + k*T;

    double theta = k * T;
    const double PI = acos(-1.0);

    double angle = 2.0 * PI * theta / 365.0;
    double lat = lat0 + T * cos(angle);
    double lon = lon0 + T * sin(angle);

    auto [dNext, mNext] = dayToDate(dayNext);

    cout << "o proximo assassinato sera dia "
         << setw(2) << setfill('0') << dNext << "/"
         << setw(2) << setfill('0') << mNext << "\n";

    cout << fixed << setprecision(2);
    cout << "As coordenadas sao lat = " << lat << "°, long = " << lon << "°\n";
    return 0;
}