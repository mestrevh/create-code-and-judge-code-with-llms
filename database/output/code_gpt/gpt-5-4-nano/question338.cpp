/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0;

    bool neg = false;
    if (!s.empty() && (s[0] == '-' || s[0] == '+')) {
        neg = (s[0] == '-');
        s = s.substr(1);
    }

    string intPart, fracPart;
    size_t pos = s.find('.');
    if (pos == string::npos) {
        intPart = s;
        fracPart = "";
    } else {
        intPart = s.substr(0, pos);
        fracPart = s.substr(pos + 1);
    }
    if (intPart.empty()) intPart = "0";

    if (fracPart.size() < 6) fracPart += string(6 - fracPart.size(), '0');
    if (fracPart.size() > 6) fracPart = fracPart.substr(0, 6);

    long long base = 0;
    for (char c : fracPart) base = base * 10 + (c - '0');

    int d2 = base / 10000;
    int d5 = base / 10;
    int d1 = base / 100000;

    int d1_frac = d1;

    string intStr = intPart;
    if (neg && !(intStr == "0")) intStr = "-" + intStr;

    long long frac2 = d2;
    long long frac5 = d5;

    if (neg) {
        if (intPart == "0") {
            intStr = "-0";
        }
    }

    long long absInt = 0;
    for (char c : intPart) absInt = absInt * 10 + (c - '0');

    long long sign = neg ? -1 : 1;

    long long intPartVal = absInt;
    if (neg) intPartVal = -intPartVal;

    auto trimZerosLeft = [&](string &x) {
        size_t i = 0;
        while (i + 1 < x.size() && x[i] == '0') i++;
        x.erase(0, i);
    };

    string t2, t5, t3, t4;

    {
        long long ip = intPartVal;
        string signStr = (ip < 0 ? "-" : "");
        long long aip = llabs(ip);

        long long frac = frac2;
        ostringstream oss;
        oss << signStr << aip << "." << setw(2) << setfill('0') << frac;
        t2 = oss.str();
        if (neg && aip == 0) t2 = "-0." + (ostringstream() << setw(2) << setfill('0') << frac, oss.str().substr(3));
    }

    {
        long long ip = intPartVal;
        string signStr = (ip < 0 ? "-" : "");
        long long aip = llabs(ip);

        long long frac = frac5;
        ostringstream oss;
        oss << signStr << aip << "." << setw(5) << setfill('0') << frac;
        t5 = oss.str();
    }

    {
        long long ip = intPartVal;
        string signStr = (ip < 0 ? "-" : "");
        long long aip = llabs(ip);

        long long frac = d1_frac;
        ostringstream oss;
        oss << signStr << aip << "." << frac;
        t3 = oss.str();
        while (t3.find('.') != string::npos && t3.back() == '0') break;
    }

    {
        long long ip = intPartVal;
        string signStr = (ip < 0 ? "-" : "");
        long long aip = llabs(ip);

        long long frac = d1_frac;
        ostringstream oss;
        oss << signStr << aip << "." << frac;
        t4 = oss.str();
    }

    cout << "|" << t2 << "|\n";
    cout << "|" << t5 << "|\n";

    string line3 = "|" + string(6, ' ') + t3 + "|";
    if ((int)t3.size() >= 1) {
        line3 = "|" + string(6, ' ') + t3 + "|";
    }
    cout << line3 << "\n";

    string line4 = "|" + t4 + string(6, ' ') + "|";
    cout << line4 << "\n";

    return 0;
}