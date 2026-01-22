/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <functional>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long N;
    long long seed, a, b, c;

    while (std::cin >> N >> seed >> a >> b >> c) {
        if (N == 1) {
            std::cout << seed << " 0\n";
            continue;
        }
        
        if (N == 0) {
            std::cout << "0 0\n";
            continue;
        }

        std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;

        long long total_sum = 0;
        long long current_num = seed;

        pq.push(current_num);
        total_sum += current_num;

        for (long long i = 1; i < N; ++i) {
            current_num = (current_num * a + b) % c;
            pq.push(current_num);
            total_sum += current_num;
        }

        long long total_cost = 0;
        while (pq.size() > 1) {
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();

            long long current_sum = first + second;
            total_cost += current_sum;
            pq.push(current_sum);
        }

        std::cout << total_sum << " " << total_cost << "\n";
    }

    return 0;
}
