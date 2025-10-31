/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, i;
    std::cin >> n >> i;
    std::vector<int> v(n);
    for (int k = 0; k < n; ++k) {
        std::cin >> v[k];
    }
    std::sort(v.begin(), v.end(), std::greater<int>());
    std::cout << v[i - 1] << '\n';
    return 0;
}
