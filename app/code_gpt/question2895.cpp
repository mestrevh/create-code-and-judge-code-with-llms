/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <string>
#include <limits>

int main() {
    int x, y, ax, ay;
    std::string name, closestName;
    double minDistance = std::numeric_limits<double>::max();

    std::cin >> x >> y;

    while (std::cin >> ax >> ay >> name) {
        double distance = std::sqrt((x - ax) * (x - ax) + (y - ay) * (y - ay));
        if (distance < 10 && distance < minDistance) {
            minDistance = distance;
            closestName = name;
        }
    }

    if (minDistance < 10) {
        std::cout << "O aluno novo é mais parecido com " << closestName << std::endl;
    } else {
        std::cout << "Aparentemente ele não é tão chato assim" << std::endl;
    }

    return 0;
}
