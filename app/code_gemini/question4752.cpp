/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    int area1 = a * b;
    int area2 = c * d;
    std::cout << std::max(area1, area2) << std::endl;
    return 0;
}
