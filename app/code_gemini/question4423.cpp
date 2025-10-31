/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int x;
    std::cin >> x;
    long long int total_glasses = 0;
    for (int i = 0; i < x; ++i) {
        int grade;
        int sum = 0;
        int count = 0;
        while (std::cin >> grade && grade != 0) {
            sum += grade;
            count++;
        }
        if (count > 0) {
            total_glasses += sum / count;
        }
    }
    std::cout << "Elas beberam " << total_glasses << " taças!" << std::endl;
    return 0;
}
