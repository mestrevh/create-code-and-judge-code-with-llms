/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> q1(n);
    std::vector<int> q2(m);

    for (int i = 0; i < n; ++i) {
        std::cin >> q1[i];
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> q2[i];
    }

    const std::vector<int>* base_queue_ptr;
    const std::vector<int>* interleave_queue_ptr;

    if (k == 1) {
        base_queue_ptr = &q2;
        interleave_queue_ptr = &q1;
    } else {
        base_queue_ptr = &q1;
        interleave_queue_ptr = &q2;
    }

    const std::vector<int>& base_queue = *base_queue_ptr;
    const std::vector<int>& interleave_queue = *interleave_queue_ptr;

    if (base_queue.empty()) {
        for (int person : interleave_queue) {
            std::cout << person << "\n";
        }
        return 0;
    }

    std::cout << base_queue[0] << "\n";
    
    size_t i = 0;
    size_t j = 1;

    while (i < interleave_queue.size() && j < base_queue.size()) {
        std::cout << interleave_queue[i++] << "\n";
        std::cout << base_queue[j++] << "\n";
    }

    while (i < interleave_queue.size()) {
        std::cout << interleave_queue[i++] << "\n";
    }

    while (j < base_queue.size()) {
        std::cout << base_queue[j++] << "\n";
    }

    return 0;
}
