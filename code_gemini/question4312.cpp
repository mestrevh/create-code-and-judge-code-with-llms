/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <iomanip>
#include <cstdio>

int main() {
    char text1_c[5101];
    char text2_c[5101];

    while (scanf("%[^\n]%*c%[^\n]%*c", text1_c, text2_c) == 2) {
        std::string text1(text1_c);
        std::string text2(text2_c);

        std::stringstream ss1(text1);
        std::string word;
        std::vector<std::string> all_words1;
        std::set<std::string> unique_words1;
        while (ss1 >> word) {
            all_words1.push_back(word);
            unique_words1.insert(word);
        }

        std::stringstream ss2(text2);
        std::vector<std::string> all_words2;
        std::set<std::string> unique_words2;
        while (ss2 >> word) {
            all_words2.push_back(word);
            unique_words2.insert(word);
        }

        double total_words = all_words1.size() + all_words2.size();
        double unique_repetitions = 0;

        if (unique_words1.size() < unique_words2.size()) {
            for (const std::string& w : unique_words1) {
                if (unique_words2.count(w)) {
                    unique_repetitions++;
                }
            }
        } else {
            for (const std::string& w : unique_words2) {
                if (unique_words1.count(w)) {
                    unique_repetitions++;
                }
            }
        }
        
        double index = 0.0;
        if (total_words > 0) {
            index = (unique_repetitions / total_words) * 100.0;
        }

        std::cout << std::fixed << std::setprecision(1) << index << std::endl;
    }

    return 0;
}
