/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, c;
    std::cin >> n >> c;
    int current_occupancy = 0;
    bool capacity_exceeded = false;
    for (int i = 0; i < n; ++i) {
        int s, e;
        std::cin >> s >> e;
        current_occupancy -= s;
        current_occupancy += e;
        if (current_occupancy > c) {
            capacity_exceeded = true;
        }
    }
    if (capacity_exceeded) {
        std::cout << "Selvagens sao dificeis de ensinar." << std::endl;
    } else {
        std::cout << "Viva a conscientizacao." << std::endl;
    }
    return 0;
}
