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
    if (!getline(cin, line)) return 0;

    bool newWord = true;
    for (char &c : line) {
        unsigned char uc = static_cast<unsigned char>(c);
        if (isalpha(uc)) {
            if (newWord) c = toupper(uc);
            else c = tolower(uc);
            newWord = false;
        } else {
            newWord = true;
        }
    }

    cout << line << "\n";
    return 0;
}