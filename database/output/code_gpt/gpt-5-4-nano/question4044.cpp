/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string keyword, encoded;
    if (!getline(cin, keyword)) return 0;
    if (!getline(cin, encoded)) return 0;

    long long X = 0;
    for (char c : keyword) X += (int)c;

    int chave = (int)(X % 26);

    auto shiftBack = [&](char enc, int dist) -> char {
        if (dist < 0) dist %= 26, dist += 26;
        int idx = enc - 'A';
        int decIdx = (idx - dist) % 26;
        if (decIdx < 0) decIdx += 26;
        return char('A' + decIdx);
    };

    string decoded;
    decoded.reserve(encoded.size());

    int k = (int)keyword.size();
    int keyPos = 0;

    for (char c : encoded) {
        if (c >= 'A' && c <= 'Z' && c != 'Ç') {
            char keyChar = keyword[keyPos];
            int kVal = keyChar - 'A';
            int cVal = c - 'A';
            int dist = (kVal - chave - cVal) % 26;
            dist = (dist + 26) % 26;

            decoded.push_back(shiftBack(c, dist));
            keyPos++;
            if (keyPos == k) keyPos = 0;
        } else if (c == '_') {
            decoded.push_back(' ');
        } else if (c == '#') {
            decoded.push_back('.');
        } else if (c == '&') {
            decoded.push_back(',');
        } else {
            decoded.push_back(c);
        }
    }

    cout << decoded;
    return 0;
}