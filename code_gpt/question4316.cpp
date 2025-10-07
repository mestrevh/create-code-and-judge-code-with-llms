/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int n;
    while (std::cin >> n) {
        std::string number;
        std::cin >> number;
        if (n == 0 && number == "0") {
            std::cout << "0" << std::endl;
            continue;
        }
        std::reverse(number.begin(), number.end());
        std::cout << std::stoll(number) << std::endl;
    }
    return 0;
}
