/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

int counts[26] = {0};

void generate(std::string current) {
    if (current.length() == 3) {
        std::cout << current;
        return;
    }

    for (int i = 0; i < 26; ++i) {
        if (counts[i] > 0) {
            counts[i]--;
            generate(current + (char)('a' + i));
            counts[i]++;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long total_sum = 0;
    std::string word;

    while (std::cin >> word) {
        std::string current_digits = "";
        for (char c : word) {
            if (isalpha(c)) {
                counts[tolower(c) - 'a']++;
            } else if (isdigit(c)) {
                current_digits += c;
            }
        }
        if (!current_digits.empty()) {
            total_sum += std::stoll(current_digits);
        }
    }

    generate("");
    std::cout << "\n";

    std::cout << "Rebeka agora esta livre! A senha da cela eh " << total_sum << "\n";

    return 0;
}
