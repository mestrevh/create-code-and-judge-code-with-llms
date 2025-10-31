/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    int i;
    std::cin >> i;

    std::vector<std::string> cores = {
        "rosa rosa verde rosa",
        "verde rosa verde rosa",
        "rosa verde rosa verde",
        "verde rosa rosa verde",
        "rosa rosa verde verde",
        "verde verde rosa rosa",
        "rosa verde verde rosa",
        "verde rosa verde verde",
        "rosa rosa rosa verde",
        "verde rosa rosa rosa",
        "rosa verde rosa rosa",
        "verde verde rosa verde"
    };

    std::cout << cores[i] << std::endl;
    return 0;
}
