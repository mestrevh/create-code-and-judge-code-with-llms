/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int i;
    std::cin >> i;
    std::vector<std::string> patterns = {
        "rosa rosa verde rosa",
        "verde rosa verde rosa",
        "rosa verde verde rosa",
        "verde verde verde rosa",
        "rosa rosa rosa verde",
        "verde rosa rosa verde",
        "rosa verde rosa verde",
        "verde verde rosa verde",
        "rosa rosa verde verde",
        "verde rosa verde verde",
        "rosa verde verde verde",
        "verde verde verde verde"
    };
    std::cout << patterns[i] << '\n';
    return 0;
}
