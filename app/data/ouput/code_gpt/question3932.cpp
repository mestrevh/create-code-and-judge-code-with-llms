/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

std::string decode(const std::string& code) {
    std::string result;
    std::istringstream stream(code);
    std::string ascii;
    int upper_count = 0, lower_count = 0;
    
    while (getline(stream, ascii, '-')) {
        if (ascii.empty()) continue;
        char ch = static_cast<char>(std::stoi(ascii));
        result += ch;
        if (isupper(ch)) upper_count++;
        else lower_count++;
    }
    return upper_count > lower_count ? result : result;
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::string output;
    size_t pos = 0, start;
    
    while ((start = input.find('[', pos)) != std::string::npos) {
        output += input.substr(pos, start - pos);
        size_t end = input.find(']', start);
        if (end != std::string::npos) {
            std::string code = input.substr(start + 1, end - start - 1);
            output += decode(code);
            pos = end + 1;
        } else {
            break;
        }
    }
    output += input.substr(pos);
    std::cout << output << std::endl;
    return 0;
}
