/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int tamstr(char* str) {
    char* p = str;
    while (*p != '\0') {
        p++;
    }
    return p - str;
}

int main() {
    char str[11];
    while (true) {
        std::cin >> str;
        if (std::string(str) == "FIM") break;
        std::cout << tamstr(str) << std::endl;
    }
    return 0;
}
