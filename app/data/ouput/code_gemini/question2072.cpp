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

    int diff = 0;
    int coins = 0;
    int side = 0; 

    for (int i = 0; i < n; ++i) {
        char move;
        std::cin >> move;

        if (move == 'C') {
            diff++;
        } else {
            diff--;
        }

        if (side == 0) {
            if (diff > 0) {
                side = 1;
            } else if (diff < 0) {
                side = -1;
            }
        } else if (side == 1) {
            if (diff < 0) {
                coins++;
                side = -1;
            }
        } else { // side == -1
            if (diff > 0) {
                coins++;
                side = 1;
            }
        }
    }

    std::cout << coins << std::endl;

    return 0;
}
