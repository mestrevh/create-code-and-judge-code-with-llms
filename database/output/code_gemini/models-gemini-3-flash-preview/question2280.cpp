/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int contar_caracteres(const char* s) {
    if (*s == '\0') {
        return 0;
    }
    return 1 + contar_caracteres(s + 1);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    char s[101];
    if (std::cin.getline(s, 101)) {
        std::cout << contar_caracteres(s) << std::endl;
    }

    return 0;
}