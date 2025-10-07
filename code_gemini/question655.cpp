/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    while (std::cin >> N && N != 0) {
        std::vector<int> H(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> H[i];
        }

        int peak_count = 0;

        for (int i = 0; i < N; ++i) {
            int prev_val = H[(i + N - 1) % N];
            int current_val = H[i];
            int next_val = H[(i + 1) % N];

            if ((current_val > prev_val && current_val > next_val) || (current_val < prev_val && current_val < next_val)) {
                peak_count++;
            }
        }
        std::cout << peak_count << "\n";
    }

    return 0;
}
