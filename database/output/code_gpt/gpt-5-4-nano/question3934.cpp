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

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    long long evenScore = 0, oddScore = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            const string &w = grid[i];
            char c = j < (int)w.size() ? w[j] : '\0';
            if (c == '\0') continue;

            int sum = i + j;
            unsigned char uc = static_cast<unsigned char>(c);
            if (sum % 2 == 0) evenScore += uc;
            else oddScore += uc;
        }
    }

    if (evenScore == oddScore) {
        cout << "Tivemos um empate em " << evenScore << " pontos!";
    } else if (evenScore > oddScore) {
        cout << "Os pares venceram com " << evenScore << " pontos!";
    } else {
        cout << "Os impares venceram com " << oddScore << " pontos!";
    }

    return 0;
}