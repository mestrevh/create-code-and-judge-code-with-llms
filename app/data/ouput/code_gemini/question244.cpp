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
    char c;
    std::cin >> s >> c;
    int count = 0;
    for (char character_in_string : s) {
        if (character_in_string == c) {
            count++;
        }
    }
    std::cout << count << std::endl;
    return 0;
}
