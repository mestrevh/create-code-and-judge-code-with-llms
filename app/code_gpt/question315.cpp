/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

std::string get_rgb(const std::string &name) {
    std::map<char, std::string> hex_map = {
        {'A', "0"}, {'B', "1"}, {'C', "2"}, {'D', "3"}, {'E', "4"},
        {'F', "5"}, {'G', "6"}, {'H', "7"}, {'I', "8"}, {'J', "9"},
        {'K', "0"}, {'L', "1"}, {'M', "2"}, {'N', "3"}, {'O', "4"},
        {'P', "5"}, {'Q', "6"}, {'R', "7"}, {'S', "8"}, {'T', "9"},
        {'U', "0"}, {'V', "1"}, {'W', "2"}, {'X', "3"}, {'Y', "4"},
        {'Z', "5"}
    };

    std::string hex_code = "c";
    for (char ch : name) {
        hex_code += hex_map[ch];
    }

    while (hex_code.length() < 12) {
        hex_code += "0";
    }
    hex_code = hex_code.substr(0, 12);

    std::string r = hex_code.substr(1, 2);
    std::string g = hex_code.substr(5, 2);
    std::string b = hex_code.substr(9, 2);

    int red = std::stoi(r, nullptr, 16);
    int green = std::stoi(g, nullptr, 16);
    int blue = std::stoi(b, nullptr, 16);

    return "(" + std::to_string(red) + "," + std::to_string(green) + "," + std::to_string(blue) + ")";
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::string result = get_rgb(input);
    std::cout << result << std::endl;
    return 0;
}
