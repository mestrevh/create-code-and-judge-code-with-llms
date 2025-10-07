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

    int joao_count = 0;
    int maria_count = 0;
    long long joao_sum = 0;
    long long maria_sum = 0;
    
    std::vector<bool> seen(13001, false);

    for (int i = 0; i < n; ++i) {
        int serial;
        std::cin >> serial;

        if (serial % 2 == 0) {
            joao_count++;
            if (!seen[serial]) {
                joao_sum += serial;
                seen[serial] = true;
            }
        } else {
            maria_count++;
            if (!seen[serial]) {
                maria_sum += serial;
                seen[serial] = true;
            }
        }
    }

    long long winner_sum;
    if (joao_sum > maria_sum) {
        winner_sum = joao_sum;
    } else {
        winner_sum = maria_sum;
    }

    std::cout << joao_count << "\n";
    std::cout << maria_count << "\n";
    std::cout << winner_sum << "\n";

    return 0;
}
