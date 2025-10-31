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
        
        int symbol_count = 0;
        std::string processed_string = "";
        std::string symbols = "*)!$+@-/()%.,?";

        for (char c : line) {
            if (symbols.find(c) != std::string::npos) {
                symbol_count++;
                continue;
            }

            if (isspace(c)) {
                continue;
            }

            if (isupper(c)) {
                processed_string += std::to_string(c - 'A' + 1);
            } else if (islower(c)) {
                if (symbol_count % 2 == 0) {
                    processed_string += toupper(c);
                } else {
                    processed_string += c;
                }
            } else if (isdigit(c)) {
                switch (c) {
                    case '0': processed_string += '*'; break;
                    case '1': processed_string += ')'; break;
                    case '2': processed_string += '$'; break;
                    case '3': processed_string += '!'; break;
                    case '4': processed_string += '+'; break;
                    case '5': processed_string += '@'; break;
                    case '6': processed_string += '-'; break;
                    case '7': processed_string += '/'; break;
                    case '8': processed_string += '('; break;
                    case '9': processed_string += '%'; break;
                }
            }
        }
        std::cout << processed_string << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();

    return 0;
}
