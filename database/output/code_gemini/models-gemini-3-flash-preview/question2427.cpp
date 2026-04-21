/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) return 0;

    size_t dash_pos = s.find('-');
    if (dash_pos == string::npos) return 0;

    string l_part = s.substr(0, dash_pos);
    string r_part = s.substr(dash_pos + 1);

    int idx;
    try {
        idx = stoi(l_part);
    } catch (...) {
        return 0;
    }

    if (idx < 1 || idx > 26) return 0;

    char letter = (char)('A' + idx - 1);

    string names[] = {
        "Meguro",
        "Shirokanedai",
        "Shirkane-Takanawa",
        "Mita",
        "Shiba-Koen",
        "Oniramon",
        "Uchi-Saiwaicho",
        "Hibiva",
        "Otemachi",
        "Jimbocho",
        "Siudobashi",
        "Kasuga",
        "Hakusan",
        "Sengoku",
        "Sugamo",
        "Nishi-Sugamo",
        "Shin- Itabashi",
        "Itabashe-Kuyakushomae",
        "Itabashi-Honcho",
        "Motohasunuma",
        "Shimura-Sakaue",
        "Shimura-Sanchome",
        "Hasune",
        "Nishidai",
        "Takashimadeira",
        "Shin-Takashimadaira"
    };

    cout << "Nós estamos indo para estação " << letter << "-" << r_part 
         << ", cujo nome é " << names[idx - 1] << "." << endl;

    return 0;
}