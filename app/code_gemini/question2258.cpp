/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

void countCharacters(const char* s) {
    int count = 0;
    while (s[count] != '\0') {
        count++;
    }
    std::cout << count << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    char s[51];
    std::cin.getline(s, 51);
    countCharacters(s);
    return 0;
}
