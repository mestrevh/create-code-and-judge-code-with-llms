/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

void solve() {
    std::string line;
    if (std::getline(std::cin, line)) {
        solve();

        int punc_count = 0;
        
        for (char c : line) {
            if (std::isspace(c)) {
                continue;
            } else if (std::isdigit(c)) {
                switch (c) {
                    case '0': std::cout << '*'; break;
                    case '1': std::cout << ')'; break;
                    case '2': std::cout << '$'; break;
                    case '3': std::cout << '!'; break;
                    case '4': std::cout << '+'; break;
                    case '5': std::cout << '@'; break;
                    case '6': std::cout << '-'; break;
                    case '7': std::cout << '/'; break;
                    case '8': std::cout << '('; break;
                    case '9': std::cout << '%'; break;
                }
            } else if (std::isupper(c)) {
                std::cout << (c - 'A' + 1);
            } else if (std::islower(c)) {
                if (punc_count % 2 == 0) {
                    std::cout << (char)std::toupper(c);
                } else {
                    std::cout << c;
                }
            } else {
                punc_count++;
            }
        }
        std::cout << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
