/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

long long sumAsciiRecursive(const std::string& s, int index) {
    if (index >= s.length()) {
        return 0;
    }
    return static_cast<long long>(s[index]) + sumAsciiRecursive(s, index + 1);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::string final_message = "";
    for (int i = 0; i < n; ++i) {
        std::string word;
        std::cin >> word;

        long long sum = sumAsciiRecursive(word, 0);
        int result = sum % 90;

        if (result < 65) {
            result = 65 + (result % 26);
        }

        final_message += static_cast<char>(result);
    }

    std::cout << final_message << std::endl;

    return 0;
}
