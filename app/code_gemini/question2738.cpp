/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

int calculate_min_swaps(std::vector<int> initial, const std::vector<int>& target) {
    if (initial == target) {
        return 0;
    }

    std::queue<std::pair<std::vector<int>, int>> q;
    std::map<std::vector<int>, bool> visited;

    q.push({initial, 0});
    visited[initial] = true;

    while (!q.empty()) {
        std::vector<int> current_vec = q.front().first;
        int dist = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            for (int j = i + 1; j < 4; ++j) {
                std::vector<int> next_vec = current_vec;
                std::swap(next_vec[i], next_vec[j]);

                if (next_vec == target) {
                    return dist + 1;
                }

                if (visited.find(next_vec) == visited.end()) {
                    visited[next_vec] = true;
                    q.push({next_vec, dist + 1});
                }
            }
        }
    }
    
    return -1; 
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> nums(4);
    std::cin >> nums[0] >> nums[1] >> nums[2] >> nums[3];

    std::vector<int> sorted_nums = nums;
    std::sort(sorted_nums.begin(), sorted_nums.end());

    std::cout << sorted_nums[0] << " " << sorted_nums[1] << " " << sorted_nums[2] << " " << sorted_nums[3] << std::endl;

    int swaps = calculate_min_swaps(nums, sorted_nums);
    std::cout << swaps << std::endl;

    return 0;
}
