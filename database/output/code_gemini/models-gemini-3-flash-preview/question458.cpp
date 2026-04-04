/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

string normalize(string s) {
    string res = "";
    for (int i = 0; i < (int)s.length(); ++i) {
        unsigned char c = (unsigned char)s[i];
        if (c >= 'A' && c <= 'Z') {
            res += (char)(c + 32);
        } else if (c == 0xC3 && i + 1 < (int)s.length()) {
            unsigned char c2 = (unsigned char)s[i+1];
            if (c2 >= 0x80 && c2 <= 0x9F) {
                res += (char)0xC3;
                res += (char)(c2 + 0x20);
                i++;
            } else {
                res += (char)c;
            }
        } else if (c != '\r' && c != '\n') {
            res += (char)c;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s_pack_raw, s_pay_raw;
    if (!getline(cin, s_pack_raw)) return 0;
    if (!getline(cin, s_pay_raw)) return 0;

    string s_pack = normalize(s_pack_raw);
    string s_pay = normalize(s_pay_raw);

    double price = 0;
    int channels = 0;
    double disc = 0;
    int extra = 0;

    string basico_acc = "b\xc3\xa1" "sico";
    string debito_acc = "d\xc3\xa9" "bito";

    if (s_pack.find(basico_acc) != string::npos || s_pack.find("basico") != string::npos) {
        price = 80.80;
        channels = 32;
        disc = 0.05;
        extra = 6;
    } else if (s_pack.find("entretenimento") != string::npos) {
        price = 100.40;
        channels = 55;
        disc = 0.05;
        extra = 6;
    } else if (s_pack.find("multicultural") != string::npos) {
        price = 130.23;
        channels = 70;
        disc = 0.10;
        extra = 11;
    } else if (s_pack.find("completo") != string::npos) {
        price = 215.50;
        channels = 112;
        disc = 0.10;
        extra = 11;
    }

    if (s_pay.find(debito_acc) != string::npos || s_pay.find("debito") != string::npos) {
        price *= (1.0 - disc);
        channels += extra;
    }

    cout << fixed << setprecision(2) << price << "\n";
    cout << channels << endl;

    return 0;
}