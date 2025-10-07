/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

void solve() {
    std::string text;
    std::cin >> text;
    int holes = 0;
    for (char c : text) {
        switch (c) {
            case 'A':
            case 'D':
            case 'O':
            case 'P':
            case 'R':
                holes += 1;
                break;
            case 'B':
                holes += 2;
                break;
        }
    }
    std::cout << holes << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
