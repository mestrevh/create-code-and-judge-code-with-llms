/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, k;
    std::cin >> n >> k;
    std::vector<std::string> names(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> names[i];
    }
    std::sort(names.begin(), names.end());
    std::cout << names[k - 1] << std::endl;
    return 0;
}
