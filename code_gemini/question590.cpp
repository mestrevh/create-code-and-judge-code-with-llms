/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

class DataCollection {
private:
    std::priority_queue<int> lower_half; // Max-heap for the smaller half
    std::priority_queue<int, std::vector<int>, std::greater<int>> upper_half; // Min-heap for the larger half
    long long current_min;
    long long current_max;
    size_t total_count;

public:
    DataCollection() {
        total_count = 0;
    }

    void add(int v) {
        if (total_count == 0) {
            current_min = v;
            current_max = v;
        } else {
            current_min = std::min(current_min, (long long)v);
            current_max = std::max(current_max, (long long)v);
        }
        total_count++;

        if (!lower_half.empty() && v <= lower_half.top()) {
            lower_half.push(v);
        } else {
            upper_half.push(v);
        }

        // Rebalance the heaps based on the median definition A[floor(N/2)]
        size_t lower_target_size = total_count / 2;
        size_t upper_target_size = total_count - lower_target_size;

        while (lower_half.size() > lower_target_size) {
            upper_half.push(lower_half.top());
            lower_half.pop();
        }
        while (upper_half.size() > upper_target_size) {
            lower_half.push(upper_half.top());
            upper_half.pop();
        }
    }

    long long get_min() const {
        if (total_count == 0) return -1;
        return current_min;
    }

    long long get_max() const {
        if (total_count == 0) return -1;
        return current_max;
    }

    long long get_med() const {
        if (total_count == 0) return -1;
        return upper_half.top();
    }

    size_t reset() {
        size_t old_count = total_count;
        total_count = 0;
        
        std::priority_queue<int> empty_lower;
        lower_half.swap(empty_lower);

        std::priority_queue<int, std::vector<int>, std::greater<int>> empty_upper;
        upper_half.swap(empty_upper);
        
        return old_count;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    DataCollection dc;
    std::string command;
    int value;

    while (std::cin >> command) {
        if (command == "ADD") {
            std::cin >> value;
            dc.add(value);
            std::cout << dc.get_min() << " " << dc.get_med() << " " << dc.get_max() << "\n";
        } else if (command == "MIN") {
            std::cout << dc.get_min() << "\n";
        } else if (command == "MAX") {
            std::cout << dc.get_max() << "\n";
        } else if (command == "MED") {
            std::cout << dc.get_med() << "\n";
        } else if (command == "RES") {
            std::cout << dc.reset() << "\n";
        }
    }

    return 0;
}
