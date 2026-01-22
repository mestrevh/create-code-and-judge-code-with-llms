/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int x, y;
    char dir;
    std::cin >> x >> y >> dir;
    switch (dir) {
        case 'w':
            y++;
            std::cout << "Nova posicao: " << x << " " << y << std::endl;
            break;
        case 'a':
            x--;
            std::cout << "Nova posicao: " << x << " " << y << std::endl;
            break;
        case 's':
            y--;
            std::cout << "Nova posicao: " << x << " " << y << std::endl;
            break;
        case 'd':
            x++;
            std::cout << "Nova posicao: " << x << " " << y << std::endl;
            break;
        default:
            std::cout << "Direcao invalida" << std::endl;
            break;
    }
    return 0;
}
