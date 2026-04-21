/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int tamstr(char* str) {
    char* p = str;
    while (*p != '\0') {
        p++;
    }
    return (int)(p - str);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    while (std::cin >> s && s != "FIM") {
        char* ptr = &s[0];
        std::cout << tamstr(ptr) << "\n";
    }

    return 0;
}