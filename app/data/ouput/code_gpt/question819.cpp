/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>
#include <string>
#include <cmath>

int main() {
    std::map<std::string, int> directionMap = {{"norte", 0}, {"leste", 90}, {"sul", 180}, {"oeste", 270}};
    std::string A, B;
    std::cin >> A >> B;
    
    int angleA = directionMap[A];
    int angleB = directionMap[B];
    int angleDifference = std::abs(angleB - angleA);
    
    if (angleDifference > 180) {
        angleDifference = 360 - angleDifference;
    }
    
    std::cout << angleDifference << std::endl;
    return 0;
}
