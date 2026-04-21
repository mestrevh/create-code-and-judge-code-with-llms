/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    while (std::cin >> n && n != 0) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::vector<std::string> guests(n);
        for (int i = 0; i < n; ++i) {
            std::getline(std::cin, guests[i]);
        }
        std::sort(guests.begin(), guests.end());
        for (int i = 0; i < n; ++i) {
            std::cout << guests[i] << "\n";
        }
    }

    return 0;
}