/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, Q;
    std::cin >> N >> Q;
    std::vector<int> cells(N);
    for (int i = 0; i < N; i++) std::cin >> cells[i];
    
    std::sort(cells.begin(), cells.end());
    std::cout << cells[0];
    for (int i = 1; i < N; i++) std::cout << " " << cells[i];
    std::cout << std::endl;

    for (int i = 0; i < Q; i++) {
        int pos;
        std::cin >> pos;
        cells[pos] += cells[(pos + 1) % N];
        cells.erase(cells.begin() + (pos + 1) % N);
        std::sort(cells.begin(), cells.end());
        
        for (int j = 0; j < cells.size(); j++) {
            std::cout << cells[j];
            if (j < cells.size() - 1) std::cout << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
