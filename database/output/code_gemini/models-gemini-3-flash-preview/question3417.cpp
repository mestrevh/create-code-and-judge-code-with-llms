/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    while (std::cin >> n && n != -1) {
        int count = 0;
        for (int i = 0; i < 10; ++i) {
            int current;
            if (std::cin >> current) {
                if (current == n) {
                    count++;
                }
            }
        }
        std::cout << n << " appeared " << count << " times\n";
    }

    return 0;
}