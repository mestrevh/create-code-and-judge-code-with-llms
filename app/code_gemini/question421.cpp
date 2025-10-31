/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>

void solve(int n) {
    bool found_solution = false;

    for (int fghij = 1234; fghij <= 98765 / n; ++fghij) {
        int abcde = fghij * n;

        std::stringstream ss;
        ss << std::setw(5) << std::setfill('0') << abcde
           << std::setw(5) << std::setfill('0') << fghij;
        std::string combined = ss.str();
        
        std::sort(combined.begin(), combined.end());
        
        if (combined == "0123456789") {
            found_solution = true;
            std::cout << std::setw(5) << std::setfill('0') << abcde
                      << " / "
                      << std::setw(5) << std::setfill('0') << fghij
                      << " = " << n << '\n';
        }
    }

    if (!found_solution) {
        std::cout << "There are no solutions for " << n << ".\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    bool first_case = true;
    while (std::cin >> n && n != 0) {
        if (!first_case) {
            std::cout << '\n';
        }
        solve(n);
        first_case = false;
    }

    return 0;
}
