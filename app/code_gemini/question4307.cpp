/*
Código criado pelo Gemini Pro 2.5
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

    int x, y, c;
    std::cin >> x >> y >> c;

    int start_q = get_quadrant(x, y);
    int target_x, target_y;

    bool is_valid_c = false;

    switch (start_q) {
        case 1:
            target_x = -1;
            target_y = -1;
            if (c == 2 || c == 4) is_valid_c = true;
            break;
        case 2:
            target_x = 1;
            target_y = -1;
            if (c == 1 || c == 3) is_valid_c = true;
            break;
        case 3:
            target_x = 1;
            target_y = 1;
            if (c == 2 || c == 4) is_valid_c = true;
            break;
        case 4:
            target_x = -1;
            target_y = 1;
            if (c == 1 || c == 3) is_valid_c = true;
            break;
    }

    if (!is_valid_c) {
        std::cout << "caminhada invalida\n";
        return 0;
    }

    int intermediate_q_Y_first = get_quadrant(x, target_y);
    
    int steps_x = std::abs(x - target_x);
    int steps_y = std::abs(y - target_y);

    if (intermediate_q_Y_first != c) {
        std::cout << steps_y << " passos em y e " << steps_x << " passos em x\n";
    } else {
        std::cout << steps_x << " passos em x e " << steps_y << " passos em y\n";
    }

    return 0;
}
