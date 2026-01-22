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

    int best_d_fallback = -1;
    int best_p_fallback = -1;

    for (int i = 0; i < n; ++i) {
        int d, p;
        std::cin >> d >> p;

        int remaining_books = n - 1 - i;

        if (d + p < remaining_books) {
            std::cout << d << " " << p << "\n";
            return 0;
        }

        if (i == 0) {
            best_d_fallback = d;
            best_p_fallback = p;
        } else {
            if (p < best_p_fallback) {
                best_p_fallback = p;
                best_d_fallback = d;
            } else if (p == best_p_fallback) {
                if (d < best_d_fallback) {
                    best_d_fallback = d;
                }
            }
        }
    }

    std::cout << best_d_fallback << " " << best_p_fallback << "\n";

    return 0;
}
