/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string s1, s2;
    std::cin >> s1 >> s2;
    if (s1 == s2) {
        std::cout << "IGUAIS\n";
    } else {
        std::cout << "DIFERENTES\n";
    }
    return 0;
}
