/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    int A, B, C;
    std::cin >> A >> B >> C;

    if (A + B <= C || A + C <= B || B + C <= A) {
        std::cout << 'n' << std::endl;
        return 0;
    }

    int max_side = std::max({A, B, C});
    int sum_squares = A * A + B * B + C * C;
    int max_side_square = max_side * max_side;

    if (sum_squares - max_side_square > max_side_square) {
        std::cout << 'a' << std::endl;
    } else if (sum_squares - max_side_square == max_side_square) {
        std::cout << 'r' << std::endl;
    } else {
        std::cout << 'o' << std::endl;
    }
    
    return 0;
}
