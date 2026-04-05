/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

string remover_especiais(string palavra) {
    const string special = ".\"(*$#:";
    for (char c : special) {
        palavra.erase(remove(palavra.begin(), palavra.end(), c), palavra.end());
    }
    return palavra;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_set<string> seen;
    string line;

    while (true) {
        if (!getline(cin, line)) break;
        if (line == "-1") break;

        size_t i = 0;
        while (i < line.size()) {
            while (i < line.size() && !isalpha((unsigned char)line[i])) i++;
            if (i >= line.size()) break;
            size_t j = i;
            while (j < line.size() && isalpha((unsigned char)line[j])) j++;
            string token = line.substr(i, j - i);

            for (char &ch : token) ch = (char)tolower((unsigned char)ch);
            token = remover_especiais(token);
            if (!token.empty()) seen.insert(token);

            i = j;
        }

        string processed;
        processed.reserve(line.size());
        for (char ch : line) {
            if (ch == '.' || ch == '"' || ch == '(' || ch == '*' || ch == '$' || ch == '#' || ch == ':')
                processed.push_back(' ');
            else
                processed.push_back(ch);
        }

        {
            stringstream ss(processed);
            string w;
            while (ss >> w) {
                for (char &ch : w) ch = (char)tolower((unsigned char)ch);
                w = remover_especiais(w);
                if (!w.empty()) {
                    bool allalpha = true;
                    for (char ch : w) {
                        if (!isalpha((unsigned char)ch)) { allalpha = false; break; }
                    }
                    if (allalpha) seen.insert(w);
                }
            }
        }
    }

    vector<string> ans(seen.begin(), seen.end());
    sort(ans.begin(), ans.end());
    if (ans.size() > 5000) ans.resize(5000);

    for (const auto &w : ans) cout << w << "\n";
    return 0;
}