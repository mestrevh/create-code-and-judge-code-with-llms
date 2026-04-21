/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static inline string trim(const string& s) {
    size_t i = 0, j = s.size();
    while (i < j && isspace((unsigned char)s[i])) i++;
    while (j > i && isspace((unsigned char)s[j - 1])) j--;
    return s.substr(i, j - i);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> lines;
    string line;
    while (getline(cin, line)) {
        line = trim(line);
        if (!line.empty()) lines.push_back(line);
    }
    if (lines.size() < 6) return 0;

    for (size_t idx = 0; idx + 5 < lines.size(); ) {
        if (idx + 5 >= lines.size()) break;

        string rua = lines[idx++];
        string num = lines[idx++];
        string bairro = lines[idx++];
        string cidade = lines[idx++];
        string estado = lines[idx++];
        string cep = lines[idx++];

        cout << rua << ", " << num << ".\n";
        cout << "Bairro: " << bairro << ". Cep: " << cep << "\n";
        cout << cidade << "/" << estado;

        if (idx + 5 < lines.size()) cout << "\n";
    }

    return 0;
}