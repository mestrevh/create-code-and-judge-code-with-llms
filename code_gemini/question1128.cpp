/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

void generate(int k, std::string current_str) {
    if (current_str.length() == k) {
        std::cout << current_str << '\n';
        return;
    }

    generate(k, current_str + '0');

    if (current_str.empty() || current_str.back() == '0') {
        generate(k, current_str + '1');
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int k;
    std::cin >> k;

    generate(k, "");

    return 0;
}
