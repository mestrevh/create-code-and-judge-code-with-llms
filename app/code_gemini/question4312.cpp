/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <iomanip>
#include <iterator>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string text1, text2;
    std::getline(std::cin, text1);
    std::getline(std::cin, text2);

    std::stringstream ss1(text1);
    std::vector<std::string> words1;
    std::string word;
    while (ss1 >> word) {
        words1.push_back(word);
    }

    std::stringstream ss2(text2);
    std::vector<std::string> words2;
    while (ss2 >> word) {
        words2.push_back(word);
    }

    double total_words = words1.size() + words2.size();

    if (total_words == 0) {
        std::cout << std::fixed << std::setprecision(1) << 0.0 << std::endl;
        return 0;
    }

    std::set<std::string> unique_words1(words1.begin(), words1.end());
    std::set<std::string> unique_words2(words2.begin(), words2.end());

    double common_unique_count = 0;
    for (const std::string& w : unique_words1) {
        if (unique_words2.count(w)) {
            common_unique_count++;
        }
    }

    double index = (common_unique_count / total_words) * 100.0;

    std::cout << std::fixed << std::setprecision(1) << index << std::endl;

    return 0;
}
