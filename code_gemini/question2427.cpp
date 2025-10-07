/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::map<std::string, std::string> stations = {
        {"A-91", "Meguro"},
        {"B-82", "Shirokanedai"},
        {"C-73", "Shirkane-Takanawa"},
        {"D-64", "Mita"},
        {"E-55", "Shiba-Koen"},
        {"F-46", "Oniramon"},
        {"G-37", "Uchi-Saiwaicho"},
        {"H-28", "Hibiva"},
        {"I-19", "Otemachi"},
        {"J-50", "Jimbocho"},
        {"K-41", "Siudobashi"},
        {"L-32", "Kasuga"},
        {"M-23", "Hakusan"},
        {"N-14", "Sengoku"},
        {"O-65", "Sugamo"},
        {"P-76", "Nishi-Sugamo"},
        {"Q-87", "Shin- Itabashi"},
        {"R-98", "Itabashe-Kuyakushomae"},
        {"S-09", "Itabashi-Honcho"},
        {"T-26", "Motohasunuma"},
        {"U-27", "Shimura-Sakaue"},
        {"V-28", "Shimura-Sanchome"},
        {"W-29", "Hasune"},
        {"X-20", "Nishidai"},
        {"Y-21", "Takashimadeira"},
        {"Z-22", "Shin-Takashimadaira"}
    };

    std::string input_line;
    std::cin >> input_line;

    size_t hyphen_pos = input_line.find('-');
    std::string letter_index_str = input_line.substr(0, hyphen_pos);
    std::string station_number_str = input_line.substr(hyphen_pos + 1);

    int letter_index = std::stoi(letter_index_str);
    char actual_letter = 'A' + letter_index - 1;

    std::string correct_code;
    correct_code += actual_letter;
    correct_code += '-';
    correct_code += station_number_str;

    std::cout << "Nós estamos indo para estação " << correct_code << ", cujo nome é " << stations[correct_code] << "." << std::endl;

    return 0;
}
