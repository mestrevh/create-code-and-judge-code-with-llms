/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    int x, y, z;
    std::cin >> x >> y;
    std::cin >> z;
    int relative_speed = y - x;
    int time_in_minutes = (z * 60) / relative_speed;
    std::cout << time_in_minutes << " minutos" << std::endl;
    return 0;
}
