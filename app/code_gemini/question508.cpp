/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t1, t2, t3, t4, t5;
    std::cin >> t1 >> t2 >> t3 >> t4 >> t5;
    int sum = t1 + t2 + t3 + t4 + t5;
    int average = sum / 5;
    int total_seconds = average * 100;
    int hours = total_seconds / 3600;
    int minutes = (total_seconds % 3600) / 60;
    int seconds = total_seconds % 60;
    std::cout << average << std::endl;
    std::cout << hours << std::endl;
    std::cout << minutes << std::endl;
    std::cout << seconds << std::endl;
    return 0;
}
