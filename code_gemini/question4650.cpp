/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

void trim(std::string& s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    std::getline(std::cin, line);

    std::stringstream ss(line);
    std::string word;
    std::vector<std::string> gerunds;

    while (std::getline(ss, word, ',')) {
        trim(word);
        if (word.length() >= 2) {
            std::string ending = word.substr(word.length() - 2);
            if (ending == "ar" || ending == "er" || ending == "ir" || ending == "or") {
                std::string gerund = word.substr(0, word.length() - 1) + "ndo";
                gerunds.push_back(gerund);
            }
        }
    }

    std::cout << gerunds.size() << "\n";
    for (const std::string& g : gerunds) {
        std::cout << g << "\n";
    }

    return 0;
}
