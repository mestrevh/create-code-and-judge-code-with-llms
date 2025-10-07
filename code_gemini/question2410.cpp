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
    int position = 1;
    int rolls = 0;
    int dice_value = 1;
    while (position != n) {
        rolls++;
        position = ((position - 1) + dice_value) % n + 1;
        dice_value = (dice_value % 6) + 1;
    }
    std::cout << rolls << std::endl;
    return 0;
}
