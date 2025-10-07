/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int C;
    std::cin >> C;

    std::string line;
    std::getline(std::cin, line); // Consume the newline character after reading C

    while (std::getline(std::cin, line) && line != "FIM") {
        std::string decrypted_message = "";
        int letter_position = 1;

        for (char ch : line) {
            if (ch == ' ') {
                decrypted_message += ' ';
            } else {
                int current_value;
                if (ch >= 'A' && ch <= 'Z') {
                    current_value = ch - 'A';
                } else {
                    current_value = (ch - 'a') + 26;
                }

                int total_shift = C + letter_position;
                
                int new_value = current_value - total_shift;
                
                new_value = (new_value % 52 + 52) % 52;

                char new_char;
                if (new_value < 26) {
                    new_char = 'A' + new_value;
                } else {
                    new_char = 'a' + (new_value - 26);
                }

                decrypted_message += new_char;
                letter_position++;
            }
        }
        std::cout << decrypted_message << '\n';
    }

    return 0;
}
