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

    int m, n;
    std::cin >> m >> n;

    std::map<std::string, int> dictionary;
    for (int i = 0; i < m; ++i) {
        std::string word;
        int value;
        std::cin >> word >> value;
        dictionary[word] = value;
    }

    for (int i = 0; i < n; ++i) {
        long long total_salary = 0;
        std::string word;
        while (std::cin >> word) {
            if (word == ".") {
                break;
            }
            auto it = dictionary.find(word);
            if (it != dictionary.end()) {
                total_salary += it->second;
            }
        }
        std::cout << total_salary << std::endl;
    }

    return 0;
}
