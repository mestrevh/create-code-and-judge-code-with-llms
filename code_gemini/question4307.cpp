/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int get_quadrant(int x, int y) {
    if (x > 0 && y > 0) return 1;
    if (x < 0 && y > 0) return 2;
    if (x < 0 && y < 0) return 3;
    if (x > 0 && y < 0) return 4;
    return 0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x_start, y_start, c;
    std::cin >> x_start >> y_start >> c;

    int q_start = get_quadrant(x_start, y_start);

    if (q_start == 0 || q_start == c) {
        std::cout << "caminhada invalida\n";
        return 0;
    }

    int x_dest, y_dest;
    switch (q_start) {
        case 1:
            x_dest = -1;
            y_dest = -1;
            break;
        case 2:
            x_dest = 1;
            y_dest = -1;
            break;
        case 3:
            x_dest = 1;
            y_dest = 1;
            break;
        case 4:
            x_dest = -1;
            y_dest = 1;
            break;
    }

    int p1_x = x_start;
    int p1_y = y_dest;
    int q_p1 = get_quadrant(p1_x, p1_y);
    
    int steps_x = std::abs(x_dest - x_start);
    int steps_y = std::abs(y_dest - y_start);

    if (q_p1 != c) {
        std::cout << steps_y << " passos em y e " << steps_x << " passos em x\n";
    } else {
        std::cout << steps_x << " passos em x e " << steps_y << " passos em y\n";
    }

    return 0;
}
