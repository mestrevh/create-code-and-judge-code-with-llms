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
    while (true) {
        if (!getline(cin, line)) break;
        if (!line.empty() && line.back() == '\r') line.pop_back();
        if (line == "NAO QUERO MAIS") break;

        int spaces = 0;
        for (unsigned char ch : line) if (ch == ' ') spaces++;

        int aCount = 0;
        for (unsigned char ch : line) {
            if (ch == 'a' || ch == 'A') aCount++;
        }

        map<string, int> freq;
        int bestCount = 0;
        string bestPair;
        bool found = false;

        for (int i = 0; i + 1 < (int)line.size(); i++) {
            unsigned char c1 = line[i], c2 = line[i + 1];
            if (!isalpha(c1) || !isalpha(c2)) continue;

            string p;
            p += (char)tolower(c1);
            p += (char)tolower(c2);

            int cnt = ++freq[p];
            if (!found || cnt > bestCount) {
                found = true;
                bestCount = cnt;
                bestPair = p;
            }
        }

        cout << spaces << "\n";
        cout << aCount << "\n";
        if (!found) {
            cout << "NENHUM PAR" << "\n";
        } else {
            cout << bestCount << "\n";
        }
        if (!found) {
            cout << "NENHUM PAR" << "\n";
        } else {
            cout << bestPair << "\n";
        }
    }

    return 0;
}