/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N;
    while (std::cin >> N && N != 0) {
        int scoreA = 0;
        int scoreB = 0;
        for (int i = 0; i < N; ++i) {
            int a, b;
            std::cin >> a >> b;
            if (a > b) {
                scoreA++;
            } else if (b > a) {
                scoreB++;
            }
        }
        std::cout << scoreA << " " << scoreB << std::endl;
    }
    return 0;
}
