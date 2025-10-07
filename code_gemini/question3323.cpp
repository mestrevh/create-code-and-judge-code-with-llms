/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, b, c;
    char x, y;
    std::cin >> a >> x >> b >> y >> c;

    if (x == 'v' && y == '^') {
        std::cout << (a || (b && c)) << std::endl;
    } else {
        int temp_res;
        if (x == '^') {
            temp_res = a && b;
        } else {
            temp_res = a || b;
        }

        if (y == '^') {
            std::cout << (temp_res && c) << std::endl;
        } else {
            std::cout << (temp_res || c) << std::endl;
        }
    }

    return 0;
}
