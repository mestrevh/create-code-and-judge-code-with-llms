/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<std::string> keywords(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> keywords[i];
    }

    std::string bits;
    std::cin >> bits;

    if (bits.empty()) {
        std::cout << "Sem bits no momento...\n";
        return 0;
    }

    long long sum = 0;
    std::string numberSequence;

    for (size_t i = 0; i < bits.length(); i += 4) {
        std::string chunk = bits.substr(i, 4);
        int current_num = std::stoi(chunk, nullptr, 2);

        sum += current_num;
        numberSequence += std::to_string(current_num);

        if (current_num > 9) {
            std::cout << "Numero invalido!\n";
        }
    }

    std::cout << "O codigo de entrada eh: " << sum << "\n";

    if (n > 0) {
        std::sort(keywords.begin(), keywords.end());
        for (const std::string& keyword : keywords) {
            std::cout << keyword << numberSequence << "\n";
        }
    }

    return 0;
}
