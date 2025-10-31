/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string n;
    std::cin >> n;
    if (n[0] == n[4] && n[1] == n[3]) {
        std::cout << "S\n";
    } else {
        std::cout << "N\n";
    }
    return 0;
}
