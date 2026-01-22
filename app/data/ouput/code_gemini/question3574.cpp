/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <string>

void solve() {
    int n, m;
    std::cin >> n >> m;

    int criancas = 0;
    int bebes = 0;
    bool chorao_presente = false;

    for (int i = 0; i < n * m; ++i) {
        int val;
        std::cin >> val;

        long long d_tri = 1 + 8LL * val;
        long long sqrt_d_tri = round(sqrt(d_tri));

        if (sqrt_d_tri * sqrt_d_tri == d_tri) {
            if ((sqrt_d_tri - 1) > 0 && (sqrt_d_tri - 1) % 2 == 0) {
                criancas++;
                continue;
            }
        }
        
        long long sqrt_val = round(sqrt(val));
        if (sqrt_val * sqrt_val == val) {
            bebes++;
            continue;
        }

        long long d_pent = 1 + 24LL * val;
        long long sqrt_d_pent = round(sqrt(d_pent));
        if (sqrt_d_pent * sqrt_d_pent == d_pent) {
            if ((sqrt_d_pent + 1) > 0 && (sqrt_d_pent + 1) % 6 == 0) {
                chorao_presente = true;
            }
        }
    }

    std::cout << "Temos " << criancas << " crianças" << std::endl;
    std::cout << "Temos " << bebes << " bebês" << std::endl;
    if (chorao_presente) {
        std::cout << "Hoje o bebê vai chorar sozinho..." << std::endl;
    } else {
        std::cout << "Oba! Kinho vai trabalhar hoje." << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
