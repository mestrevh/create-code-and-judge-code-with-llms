/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    long long nth_triangular = (long long)n * (n + 1) / 2;
    long long sum_triangulars = (long long)n * (n + 1) * (n + 2) / 6;
    std::cout << nth_triangular << " " << sum_triangulars << " ";
    if (nth_triangular % 2 == 0 && sum_triangulars % 2 == 0) {
        std::cout << 'P' << '\n';
    } else if (nth_triangular % 2 != 0 && sum_triangulars % 2 != 0) {
        std::cout << 'I' << '\n';
    } else {
        std::cout << 'N' << '\n';
    }
    return 0;
}
