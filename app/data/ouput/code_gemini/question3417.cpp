/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    while (std::cin >> n && n != -1) {
        int count = 0;
        for (int i = 0; i < 1000; ++i) {
            int current_number;
            std::cin >> current_number;
            if (current_number == n) {
                count++;
            }
        }
        std::cout << n << " appeared " << count << " times\n";
    }
    return 0;
}
