/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isLess(const string& a, const string& b) {
    if (a.length() < b.length()) return true;
    if (a.length() > b.length()) return false;
    return a < b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string n_str;
    if (!(cin >> n_str)) return 0;

    string clean_n = "";
    for (char c : n_str) {
        if (c >= '0' && c <= '9') {
            clean_n += c;
        }
    }

    if (clean_n.empty()) return 0;

    size_t first = clean_n.find_first_not_of('0');
    if (string::npos == first) {
        clean_n = "0";
    } else {
        clean_n = clean_n.substr(first);
    }

    const string perfects[] = {
        "6",
        "28",
        "496",
        "8128",
        "33550336",
        "8589869056",
        "137438691328",
        "2305843008139952128",
        "2658455991569831744654692615953842176",
        "191561942608236107294793378084303638130997321548169216",
        "14474011154664524427946373126085988481573677491474835889066354349131199152128"
    };

    for (const string& p : perfects) {
        if (isLess(p, clean_n)) {
            cout << p << "\n";
        } else {
            break;
        }
    }

    return 0;
}