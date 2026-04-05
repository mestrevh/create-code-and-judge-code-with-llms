/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string sL, sM, sR;
    if (!(cin >> sL)) return 0;
    cin >> sM >> sR;

    const string target = "bowser";

    auto canForm = [&](const string& s) -> bool {
        int j = 0;
        for (char c : s) {
            if (j < (int)target.size() && c == target[j]) j++;
        }
        return j == (int)target.size();
    };

    if (canForm(sL)) cout << "Esquerda";
    else if (canForm(sM)) cout << "Meio";
    else cout << "Direita";

    return 0;
}