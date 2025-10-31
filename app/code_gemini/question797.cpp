/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

void solve() {
    std::string encrypted_text;
    std::getline(std::cin, encrypted_text);

    int c = encrypted_text.length();
    if (c == 0) {
        std::cout << "INVALIDO\n";
        return;
    }

    int n = static_cast<int>(sqrt(c));

    if (n * n != c) {
        std::cout << "INVALIDO\n";
        return;
    }

    std::vector<std::vector<char>> matrix(n, std::vector<char>(n));
    int k = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = encrypted_text[k++];
        }
    }

    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            std::cout << matrix[i][j];
        }
    }
    std::cout << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    std::cin.ignore();

    while (t--) {
        solve();
    }

    return 0;
}
