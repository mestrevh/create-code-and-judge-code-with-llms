/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, K;
    if (!(std::cin >> N >> K)) return 0;

    std::vector<std::string> students(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> students[i];
    }

    std::sort(students.begin(), students.end());

    std::cout << students[K - 1] << "\n";

    return 0;
}