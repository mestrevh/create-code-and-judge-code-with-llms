/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

struct LetterCount {
    char letter;
    int count;
};

bool compareLetterCounts(const LetterCount& a, const LetterCount& b) {
    if (a.count != b.count) {
        return a.count > b.count;
    }
    return a.letter < b.letter;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    int test_case_num = 1;
    while (std::cin >> n && n != 0) {
        std::cin.ignore(); 

        std::vector<int> counts(26, 0);

        for (int i = 0; i < n; ++i) {
            std::string line;
            std::getline(std::cin, line);
            for (char c : line) {
                if (std::isalpha(c)) {
                    counts[std::toupper(c) - 'A']++;
                }
            }
        }

        std::vector<LetterCount> results;
        for (int i = 0; i < 26; ++i) {
            if (counts[i] > 0) {
                results.push_back({(char)('A' + i), counts[i]});
            }
        }

        std::sort(results.begin(), results.end(), compareLetterCounts);

        std::cout << "TESTE " << test_case_num++ << std::endl;
        for (const auto& result : results) {
            std::cout << result.letter << " " << result.count << std::endl;
        }
    }

    return 0;
}
