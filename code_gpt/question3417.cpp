/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    int N, num, count;
    
    while (true) {
        std::cin >> N;
        if (N == -1) break;
        
        count = 0;
        for (int i = 0; i < 1000; ++i) {
            std::cin >> num;
            if (num == N) count++;
        }
        std::cout << N << " appeared " << count << " times\n";
    }
    
    return 0;
}
