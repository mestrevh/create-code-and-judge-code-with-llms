/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

void printReverseLines(const vector<string>& lines, int idx) {
    if (idx < 0) return;
    cout << lines[idx];
    if (idx > 0) cout << "\n";
    printReverseLines(lines, idx - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> lines;
    string line;
    while (getline(cin, line)) lines.push_back(line);

    if (!lines.empty()) printReverseLines(lines, (int)lines.size() - 1);
    return 0;
}