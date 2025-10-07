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
    std::string s;
    std::cin >> s;
    std::string even_pos;
    std::string odd_pos;
    for (int i = 0; i < s.length(); ++i) {
        if (i % 2 == 0) {
            even_pos += s[i];
        } else {
            odd_pos += s[i];
        }
    }
    std::string reversed_s = s;
    std::reverse(reversed_s.begin(), reversed_s.end());
    std::cout << "Somente posições pares: " << even_pos << '\n';
    std::cout << "Somente posições ímpares: " << odd_pos << '\n';
    std::cout << "De trás para frente: " << reversed_s << '\n';
    return 0;
}
