/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cstring>

int tamstr(char* str) {
    char* p = str;
    while (*p != '\0') {
        p++;
    }
    return p - str;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    char s[20];
    while (std::cin >> s) {
        if (strcmp(s, "FIM") == 0) {
            break;
        }
        std::cout << tamstr(s) << '\n';
    }
    return 0;
}
