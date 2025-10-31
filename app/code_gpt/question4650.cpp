/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <sstream>
#include <vector>

std::string toGerund(const std::string& verb) {
    if (verb.size() < 2) return "";
    if (verb.substr(verb.size() - 2) == "ar") return verb.substr(0, verb.size() - 2) + "ando";
    if (verb.substr(verb.size() - 2) == "er") return verb.substr(0, verb.size() - 2) + "endo";
    if (verb.substr(verb.size() - 2) == "ir") return verb.substr(0, verb.size() - 2) + "indo";
    if (verb.substr(verb.size() - 2) == "or") return verb.substr(0, verb.size() - 2) + "endo"; // Considerando or como "er"
    return "";
}

int main() {
    std::string input;
    getline(std::cin, input);
    
    std::stringstream ss(input);
    std::string word;
    std::vector<std::string> gerunds;

    while (getline(ss, word, ',')) {
        word.erase(0, word.find_first_not_of(" \t\n"));
        word.erase(word.find_last_not_of(" \t\n") + 1);
        
        std::string gerund = toGerund(word);
        if (!gerund.empty()) {
            gerunds.push_back(gerund);
        }
    }

    std::cout << gerunds.size() << std::endl;
    for (const auto& g : gerunds) {
        std::cout << g << std::endl;
    }

    return 0;
}
