/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n;
    if (std::cin >> n) {
        long long total_pills = n * 35;
        long long days = total_pills / 4;
        long long remainder = total_pills % 4;
        std::cout << days << "\n" << remainder << "\n";
    }

    return 0;
}