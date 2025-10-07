/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int b, c;
    std::cin >> b >> c;
    int area_kept = (b + c) * 35;
    int half_total_area = 5600;
    std::cout << area_kept << std::endl;
    if (area_kept > half_total_area) {
        std::cout << 1 << std::endl;
    } else if (area_kept < half_total_area) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }
    return 0;
}
