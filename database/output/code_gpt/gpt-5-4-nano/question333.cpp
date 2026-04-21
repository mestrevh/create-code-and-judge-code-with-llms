/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    string line;
    getline(cin, line);

    bool newSentence = true;
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        for (size_t j = 0; j < line.size(); j++) {
            if (newSentence && islower((unsigned char)line[j])) line[j] = (char)toupper((unsigned char)line[j]);
            newSentence = (line[j] == '.');
        }
        cout << line << "\n";
    }
    return 0;
}