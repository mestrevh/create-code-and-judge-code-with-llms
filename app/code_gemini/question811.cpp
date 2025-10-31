/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    int test_case_count = 1;
    while (std::cin >> n && n != 0) {
        int winner = 0;
        for (int i = 1; i <= n; ++i) {
            int ticket;
            std::cin >> ticket;
            if (ticket == i) {
                winner = ticket;
            }
        }
        std::cout << "Teste " << test_case_count++ << "\n";
        std::cout << winner << "\n\n";
    }
    return 0;
}
