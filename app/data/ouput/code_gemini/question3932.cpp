/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    std::getline(std::cin, line);

    std::string result = "";
    size_t last_pos = 0;
    size_t start_pos;

    while ((start_pos = line.find('[', last_pos)) != std::string::npos) {
        result.append(line, last_pos, start_pos - last_pos);

        size_t end_pos = line.find(']', start_pos);
        if (end_pos == std::string::npos) {
            result.append(line, last_pos, std::string::npos);
            last_pos = line.length();
            break;
        }

        std::string content = line.substr(start_pos + 1, end_pos - start_pos - 1);

        std::string decoded_word = "";
        std::string current_number_str = "";
        for (char c : content) {
            if (std::isdigit(static_cast<unsigned char>(c))) {
                current_number_str += c;
            } else if (c == '-') {
                if (!current_number_str.empty()) {
                    try {
                        int ascii_code = std::stoi(current_number_str);
                        decoded_word += static_cast<char>(ascii_code);
                    } catch (const std::invalid_argument& ia) {
                        // Handle error if needed, problem implies valid numbers
                    } catch (const std::out_of_range& oor) {
                        // Handle error if needed
                    }
                    current_number_str = "";
                }
            }
        }

        int upper_count = 0;
        int lower_count = 0;
        for (char c : decoded_word) {
            if (std::isupper(static_cast<unsigned char>(c))) {
                upper_count++;
            } else if (std::islower(static_cast<unsigned char>(c))) {
                lower_count++;
            }
        }

        if (upper_count > lower_count) {
            std::transform(decoded_word.begin(), decoded_word.end(), decoded_word.begin(),
                           [](unsigned char c){ return std::toupper(c); });
        } else {
            std::transform(decoded_word.begin(), decoded_word.end(), decoded_word.begin(),
                           [](unsigned char c){ return std::tolower(c); });
        }

        result.append(decoded_word);
        last_pos = end_pos + 1;
    }

    if (last_pos < line.length()) {
        result.append(line, last_pos, std::string::npos);
    }

    std::cout << result << std::endl;

    return 0;
}
