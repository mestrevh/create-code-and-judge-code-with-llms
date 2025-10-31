/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string name;
    int age;
    while (std::cin >> name >> age) {
        long long days_lived = age * 365LL;
        std::cout << name << ", você já viveu " << days_lived << " dias!" << std::endl;
    }
    return 0;
}
