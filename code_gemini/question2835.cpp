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
    std::string text;
    std::getline(std::cin, text);
    std::map<char, int> freq;
    for (char c : text) {
        freq[c]++;
    }
    for (auto it = freq.rbegin(); it != freq.rend(); ++it) {
        std::cout << it->first << " " << it->second << "\n";
    }
    return 0;
}
