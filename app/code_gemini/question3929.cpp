/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::string text;
    std::cin >> text;

    int shift;
    std::cin >> shift;

    for (char &c : text) {
        if (c >= 'a' && c <= 'z') {
            int original_pos = c - 'a';
            int new_pos = (original_pos + shift) % 26;
            c = 'a' + new_pos;
        }
    }

    std::cout << text << std::endl;

    return 0;
}
