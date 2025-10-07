/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<std::string> substrings;
    
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;

        if (s.empty()) {
            continue;
        }

        int len = s.length();
        int x = static_cast<int>(floor(sqrt(len)));
        
        size_t first_vowel_pos = s.find_first_of("AEIOU");

        if (first_vowel_pos != std::string::npos) {
            substrings.push_back(s.substr(first_vowel_pos, x));
        }
    }

    std::sort(substrings.begin(), substrings.end());

    for (const std::string& sub : substrings) {
        std::cout << sub;
    }

    return 0;
}
