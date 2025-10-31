/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    std::cin >> T;
    for (int i = 1; i <= T; ++i) {
        std::string x;
        std::cin >> x;
        std::sort(x.begin(), x.end(), std::greater<char>());
        std::cout << "Caso " << i << ": " << x << std::endl;
    }
    return 0;
}
