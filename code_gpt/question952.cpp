/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

int main() {
    std::string input;
    std::getline(std::cin, input);
    
    std::unordered_map<char, int> freq;
    std::string target = "vou passar em p1";
    
    for (char c : input) {
        c = tolower(c);
        if (strchr(target.c_str(), c)) {
            freq[c]++;
        }
    }

    std::unordered_map<char, int> targetFreq;
    for (char c : target) {
        if (c != ' ') targetFreq[c]++;
    }

    int count = INT_MAX;
    for (auto pair : targetFreq) {
        count = std::min(count, freq[pair.first] / pair.second);
    }

    std::cout << count << std::endl;
    return 0;
}
