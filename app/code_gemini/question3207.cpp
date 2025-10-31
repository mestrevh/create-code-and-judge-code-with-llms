/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string number_str;
    std::cin >> number_str;
    std::reverse(number_str.begin(), number_str.end());
    std::cout << number_str << std::endl;
    return 0;
}
