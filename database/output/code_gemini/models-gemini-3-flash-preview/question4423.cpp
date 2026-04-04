/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x;
    if (!(std::cin >> x)) return 0;

    long long total_glasses = 0;
    for (int i = 0; i < x; ++i) {
        long long current_sum = 0;
        long long count = 0;
        int grade;
        while (std::cin >> grade && grade != 0) {
            current_sum += grade;
            count++;
        }
        if (count > 0) {
            total_glasses += (current_sum / count);
        }
    }

    std::cout << "Elas beberam " << total_glasses << " taças!" << std::endl;

    return 0;
}