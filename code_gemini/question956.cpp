/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int num;
    int min_val, max_val;

    std::cin >> num;
    min_val = num;
    max_val = num;

    while (std::cin >> num && num != 0) {
        if (num < min_val) {
            min_val = num;
        }
        if (num > max_val) {
            max_val = num;
        }
    }

    std::cout << min_val << " " << max_val << std::endl;

    return 0;
}
