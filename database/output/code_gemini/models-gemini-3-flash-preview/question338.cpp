/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

string getFixed(const string& ip, const string& fp, int d) {
    string res = ip + ".";
    for (int i = 0; i < d; ++i) {
        if (i < (int)fp.size()) {
            res += fp[i];
        } else {
            res += '0';
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) return 0;

    size_t dot = s.find('.');
    string ip, fp;
    if (dot == string::npos) {
        ip = s;
        fp = "";
    } else {
        ip = s.substr(0, dot);
        fp = s.substr(dot + 1);
    }

    if (ip == "") ip = "0";
    else if (ip == "-") ip = "-0";

    string f2 = getFixed(ip, fp, 2);
    string f5 = getFixed(ip, fp, 5);
    string f1 = getFixed(ip, fp, 1);

    cout << "|" << f2 << "|\n";
    cout << "|" << f5 << "|\n";
    cout << "|      " << f1 << "|\n";
    cout << "|" << f1 << "      |\n";

    return 0;
}