/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    
    std::vector<int> travelTime(N);
    std::vector<int> busInterval(N);
    
    for (int i = 0; i < N; ++i) {
        std::cin >> travelTime[i];
    }
    
    for (int i = 0; i < N; ++i) {
        std::cin >> busInterval[i];
    }
    
    int totalTime = 0;
    
    for (int i = 0; i < N; ++i) {
        totalTime += travelTime[i];
        if (i < N - 1) {
            int waitTime = (totalTime % busInterval[i] == 0) ? 0 : busInterval[i] - (totalTime % busInterval[i]);
            totalTime += waitTime;
        }
    }
    
    std::cout << totalTime << std::endl;
    
    return 0;
}
