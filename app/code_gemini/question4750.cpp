/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    int diff1 = std::abs((a + b) - (c + d));
    int diff2 = std::abs((a + c) - (b + d));
    int diff3 = std::abs((a + d) - (b + c));
    int result = std::min(diff1, std::min(diff2, diff3));
    std::cout << result << std::endl;
    return 0;
}
