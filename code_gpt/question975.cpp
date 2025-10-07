/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

std::string decode(const std::string &input) {
    std::string output;
    for (char c : input) {
        if (isdigit(c)) {
            int num = c - '0';
            for (int i = 0; i < num; ++i) output += ' ';
        } else {
            if (c == '4') output += 'a';
            else if (c == '5') output += 'e';
            else if (c == '1') output += 'i';
            else if (c == '0') output += 'o';
            else if (c == '2') output += 'u';
            else output += c;
        }
    }
    if (!output.empty()) output[0] = toupper(output[0]);
    for (size_t i = 1; i < output.size(); ++i) {
        if (output[i - 1] == '.') output[i] = toupper(output[i]);
    }
    return output;
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::string output = decode(input);
    std::cout << output << std::endl;
    return 0;
}
