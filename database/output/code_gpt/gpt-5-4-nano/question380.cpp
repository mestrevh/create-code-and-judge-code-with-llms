/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static string normalize(string s) {
    for (char &c : s) {
        if (c >= 'A' && c <= 'Z') c = char(c - 'A' + 'a');
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    int cinema = 0, boliche = 0;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        line.erase(remove_if(line.begin(), line.end(), [](unsigned char ch){ return isspace(ch); }), line.end());
        if (line.empty()) continue;

        string t = normalize(line);
        if (t == "cinema") cinema++;
        else if (t == "boliche") boliche++;
    }

    cout << (cinema >= boliche ? "CINEMA" : "BOLICHE") << "\n";
    return 0;
}