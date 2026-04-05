/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

struct Letter {
    string rawDate;
    string sender;
    string recipient;
    int d, m, y;
    string sLow, rLow;
};

string toLower(string s) {
    string res = s;
    for (char &c : res) {
        c = (char)tolower((unsigned char)c);
    }
    return res;
}

int getMonth(string m) {
    m = toLower(m);
    if (m == "janeiro") return 1;
    if (m == "fevereiro") return 2;
    if (m == "marco" || m == "março") return 3;
    if (m == "abril") return 4;
    if (m == "maio") return 5;
    if (m == "junho") return 6;
    if (m == "julho") return 7;
    if (m == "agosto") return 8;
    if (m == "setembro") return 9;
    if (m == "outubro") return 10;
    if (m == "novembro") return 11;
    if (m == "dezembro") return 12;
    return 0;
}

bool compareLetters(const Letter &a, const Letter &b) {
    if (a.y != b.y) return a.y < b.y;
    if (a.m != b.m) return a.m < b.m;
    if (a.d != b.d) return a.d < b.d;
    if (a.sLow != b.sLow) return a.sLow < b.sLow;
    return a.rLow < b.rLow;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    string dummy;
    getline(cin, dummy);

    vector<Letter> letters;
    letters.reserve(n);
    for (int i = 0; i < n; ++i) {
        Letter L;
        if (!getline(cin, L.rawDate)) break;
        if (!getline(cin, L.sender)) break;
        if (!getline(cin, L.recipient)) break;

        stringstream ss(L.rawDate);
        string de1, mStr, de2;
        int dVal, yVal;
        if (ss >> dVal >> de1 >> mStr >> de2 >> yVal) {
            L.d = dVal;
            L.m = getMonth(mStr);
            L.y = yVal;
        } else {
            L.d = L.m = L.y = 0;
        }
        L.sLow = toLower(L.sender);
        L.rLow = toLower(L.recipient);
        letters.push_back(L);
    }

    sort(letters.begin(), letters.end(), compareLetters);

    for (int i = 0; i < (int)letters.size(); ++i) {
        cout << letters[i].rawDate << "\n";
        cout << letters[i].sender << "\n";
        cout << letters[i].recipient << "\n";
    }

    return 0;
}