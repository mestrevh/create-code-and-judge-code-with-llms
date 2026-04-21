/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    if (!(cin >> K)) return 0;
    string line;
    getline(cin, line);

    vector<long long> freq(256, 0);
    for (int i = 0; i < K; i++) {
        getline(cin, line);
        for (unsigned char c : line) freq[c]++;
        freq['\n']++;
    }

    char X;
    string xs;
    if (!(cin >> xs)) return 0;
    if (xs.size() == 1) X = xs[0];
    else X = xs[0];

    long long bestFreq = -1;
    int bestChar = 0;
    for (int c = 0; c < 256; c++) {
        if (freq[c] > bestFreq) {
            bestFreq = freq[c];
            bestChar = c;
        } else if (freq[c] == bestFreq && c < bestChar) {
            bestChar = c;
        }
    }

    cout << char(bestChar) << ' ' << bestFreq << ' ' << freq[(unsigned char)X];
    return 0;
}