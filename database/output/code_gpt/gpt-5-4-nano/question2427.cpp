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
    if (!getline(cin, s)) return 0;

    s.erase(remove_if(s.begin(), s.end(), [](unsigned char c){ return isspace(c); }), s.end());
    if (s.empty()) return 0;

    auto pos = s.find('-');
    string a = (pos == string::npos) ? s : s.substr(0, pos);
    string b = (pos == string::npos) ? "" : s.substr(pos + 1);

    int idx = 0;
    try { idx = stoi(a); } catch (...) { idx = 0; }
    char letter = char('A' + (idx - 1));
    int num = 0;
    try { num = stoi(b); } catch (...) { num = 0; }

    string names[26] = {
        "Meguro","Shirokanedai","Shirkane-Takanawa","Mita","Shiba-Koen","Oniramon","Uchi-Saiwaicho",
        "Hibiva","Otemachi","Jimbocho","Siudobashi","Kasuga","Hakusan","Sengoku","Sugamo","Nishi-Sugamo",
        "Shin-Itabashi","Itabashe-Kuyakushomae","Itabashi-Honcho","Motohasunuma","Shimura-Sakaue",
        "Shimura-Sanchome","Hasune","Nishidai","Takashimadeira","Shin-Takashimadaira"
    };

    int i = letter - 'A';
    string code = string(1, letter) + "-" + to_string(num);

    cout << "Nós estamos indo para estação " << code << ", cujo nome é " << names[i] << "." << "\n";
    return 0;
}