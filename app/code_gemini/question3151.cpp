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

    std::vector<bool> infected(101, false);

    infected[0] = true;

    for (int a = 1; a <= 19; ++a) {
        for (int b = a; b <= 19; ++b) {
            int c = 19 - a - b;
            if (c >= b) {
                long long product = (long long)a * b * c;
                if (product <= 100) {
                    infected[product] = true;
                }
            }
        }
    }

    for (int y = 1; y <= 100; ++y) {
        for (int z = y; z <= 100; ++z) {
            long long x_val = 19 + y + z;
            long long product = x_val * y * z;
            if (product > 100) {
                break;
            }
            infected[product] = true;
        }
        long long min_product = (long long)(19 + y + y) * y * y;
        if (min_product > 100) {
            break;
        }
    }

    int n;
    while (std::cin >> n && n != -1) {
        if (infected[n]) {
            std::cout << "INFECTADO\n";
        } else {
            std::cout << "SAFE\n";
        }
    }

    return 0;
}
