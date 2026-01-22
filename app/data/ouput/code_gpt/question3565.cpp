/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

int main() {
    int N, X;
    while (true) {
        std::cin >> N;
        if (N == -1) break;
        std::cin >> X;
        std::vector<int> arr(N), sortedArr(N);
        for (int i = 0; i < N; i++) {
            std::cin >> arr[i];
            sortedArr[i] = arr[i];
        }
        std::sort(sortedArr.begin(), sortedArr.end());
        
        int count = 0;
        std::vector<int> positions;
        for (int i = 0; i < N; i++) {
            if (std::abs(sortedArr[i] - arr[i]) == X) {
                count++;
                positions.push_back(i + 1);
            }
        }
        
        std::cout << count << std::endl;
        if (count > 0) {
            for (int i : positions) {
                std::cout << i << " ";
            }
            std::cout << std::endl;
        }
    }
    return 0;
}
