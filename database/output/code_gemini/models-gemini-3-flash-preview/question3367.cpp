/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    if (std::cin >> s) {
        int last_digit = s.back() - '0';
        std::cout << "O numero " << s << " eh ";
        if (last_digit % 2 == 0) {
            std::cout << "par!\n";
        } else {
            std::cout << "impar!\n";
        }
    }

    return 0;
}