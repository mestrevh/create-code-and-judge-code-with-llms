/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    string bestWord;
    int bestLen = -1;

    bool firstOutput = true;

    while (true) {
        if (!getline(cin, line)) break;
        if (line.empty()) continue;

        stringstream ss(line);
        vector<string> words;
        string w;
        while (ss >> w) words.push_back(w);

        if (words.empty()) continue;
        if (words.size() == 1 && words[0] == "0") break;

        if (!firstOutput) cout << "\n";
        firstOutput = false;

        for (size_t i = 0; i < words.size(); i++) {
            if (i) cout << " - ";
            cout << words[i].size();
            if ((int)words[i].size() >= bestLen) {
                bestLen = (int)words[i].size();
                bestWord = words[i];
            }
        }
        cout << "\n";
    }

    cout << "Maior palavra: " << bestWord;
    return 0;
}