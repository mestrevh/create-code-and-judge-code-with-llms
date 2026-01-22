/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::vector<std::string> lines(n);
    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, lines[i]);
    }
    for (int i = n - 1; i >= 0; --i) {
        std::cout << lines[i];
    }
    return 0;
}
