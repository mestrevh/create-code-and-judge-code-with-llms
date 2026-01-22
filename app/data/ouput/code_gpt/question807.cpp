/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <unordered_map>
#include <sstream>

int main() {
    int N;
    std::cin >> N;
    std::unordered_map<std::string, std::string> dictionary;
    std::string line, word, arrow, translation;

    std::getline(std::cin, line); // Consume the newline after N

    for (int i = 0; i < N; ++i) {
        std::getline(std::cin, line);
        std::istringstream iss(line);
        iss >> word >> arrow >> translation;
        dictionary[word] = translation;
    }

    while (true) {
        std::getline(std::cin, line);
        if (line == "*") break;
        std::istringstream stream(line);
        std::string result;
        while (stream >> word) {
            if (dictionary.count(word)) {
                result += dictionary[word] + " ";
            } else {
                result += word + " ";
            }
        }
        std::cout << result.substr(0, result.size() - 1) << "\n";
    }

    return 0;
}
