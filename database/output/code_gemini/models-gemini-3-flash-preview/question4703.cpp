/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

void contar_vogais(const std::string& s) {
    int a = 0, e = 0, i = 0, o = 0, u = 0;
    for (char c : s) {
        char low = std::tolower(static_cast<unsigned char>(c));
        if (low == 'a') a++;
        else if (low == 'e') e++;
        else if (low == 'i') i++;
        else if (low == 'o') o++;
        else if (low == 'u') u++;
    }
    std::cout << "A: " << a << "\n";
    std::cout << "E: " << e << "\n";
    std::cout << "I: " << i << "\n";
    std::cout << "O: " << o << "\n";
    std::cout << "U: " << u << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string input;
    if (!(std::cin >> input)) return 0;
    
    contar_vogais(input);

    return 0;
}