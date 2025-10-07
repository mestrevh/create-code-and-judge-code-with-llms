/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    int winner = -1;
    for (int i = 1; i <= n; ++i) {
        int ticket;
        std::cin >> ticket;
        if (i == ticket) {
            winner = ticket;
        }
    }
    std::cout << "o ingresso de numero " << winner << " foi sorteado\n";
    return 0;
}
