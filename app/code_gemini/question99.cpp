/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

struct Sprinkler {
    int id;
    double temp;
    char smoke;
};

void solve(int test_case_num) {
    std::cout << "TESTE " << test_case_num << '\n';

    int n;
    std::cin >> n;

    if (n == 0) {
        return;
    }

    std::vector<Sprinkler> sprinklers(n);
    double total_temp = 0.0;

    for (int i = 0; i < n; ++i) {
        std::cin >> sprinklers[i].id >> sprinklers[i].temp >> sprinklers[i].smoke;
        total_temp += sprinklers[i].temp;
    }

    double avg_temp = total_temp / static_cast<double>(n);

    for (const auto& s : sprinklers) {
        if (s.smoke == 'S' || s.temp >= 40.0 || s.temp > avg_temp * 1.15) {
            std::cout << s.id << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve(i);
    }

    return 0;
}
