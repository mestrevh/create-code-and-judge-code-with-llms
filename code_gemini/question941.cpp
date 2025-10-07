/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        if (val % 2 == 0) {
            sum += 1;
        } else {
            sum -= 1;
        }
    }
    std::cout << sum << std::endl;
    return 0;
}
