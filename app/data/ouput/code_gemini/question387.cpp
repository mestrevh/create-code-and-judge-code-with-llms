/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int cards[5];
    for (int i = 0; i < 5; ++i) {
        std::cin >> cards[i];
    }

    bool increasing = true;
    for (int i = 0; i < 4; ++i) {
        if (cards[i] > cards[i+1]) {
            increasing = false;
            break;
        }
    }

    if (increasing) {
        std::cout << 'C';
        return 0;
    }

    bool decreasing = true;
    for (int i = 0; i < 4; ++i) {
        if (cards[i] < cards[i+1]) {
            decreasing = false;
            break;
        }
    }

    if (decreasing) {
        std::cout << 'D';
    } else {
        std::cout << 'N';
    }

    return 0;
}
