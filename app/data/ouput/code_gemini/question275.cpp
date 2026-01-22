/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int h1, m1, h2, m2;
    std::cin >> h1 >> m1 >> h2 >> m2;
    int count = 0;
    int current_h = h1;
    int current_m = m1;
    while (true) {
        if (current_h == h2 && current_m == m2) {
            break;
        }
        current_m++;
        if (current_m == 60) {
            current_m = 0;
            current_h++;
            if (current_h == 13) {
                current_h = 1;
            }
        }
        if (current_h != 12 && current_m == current_h * 5) {
            count++;
        }
    }
    std::cout << count << std::endl;
    return 0;
}
