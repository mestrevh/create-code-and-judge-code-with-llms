/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int num;
    int min_val = 10001;
    int max_val = -1;

    while (std::cin >> num && num != 0) {
        if (num < min_val) min_val = num;
        if (num > max_val) max_val = num;
    }

    if (max_val != -1) {
        std::cout << min_val << " " << max_val << "\n";
    }

    return 0;
}