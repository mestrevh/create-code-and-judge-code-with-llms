/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <sstream>

std::string encrypt(int coord) {
    return std::to_string((coord - 1) + (coord + 1));
}

int main() {
    int x, y;
    std::cin >> x >> y;
    
    std::ostringstream oss;
    oss << std::uppercase << std::hex << encrypt(x);
    std::string encryptedX = oss.str();
    
    oss.str("");
    oss.clear();
    oss << std::uppercase << std::hex << encrypt(y);
    std::string encryptedY = oss.str();
    
    std::cout << "X = " << encryptedX << "\n";
    std::cout << "Y = " << encryptedY << "\n";
    
    return 0;
}
