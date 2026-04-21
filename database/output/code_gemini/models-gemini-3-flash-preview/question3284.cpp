/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    // Standard competitive programming I/O optimization
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int X;
    // Banknote denominations in descending order to satisfy greedy approach
    const int denominations[] = {100, 50, 20, 10, 5, 2, 1};

    // Handle multiple test cases as per the 'multiplas entradas' topic
    while (std::cin >> X) {
        for (int i = 0; i < 7; ++i) {
            int count = X / denominations[i];
            X %= denominations[i];
            // Format output according to the requirement: count nota(s) de R$ value,00
            std::cout << count << " nota(s) de R$ " << denominations[i] << ",00\n";
        }
    }

    return 0;
}