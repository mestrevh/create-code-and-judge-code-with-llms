/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

void backtrack(std::vector<int>& nums, std::vector<bool>& visited, std::string& current, std::vector<std::string>& result) {
    if (current.size() == nums.size()) {
        result.push_back(current);
        return;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (visited[i]) continue;
        visited[i] = true;
        current.push_back(nums[i] + '0');
        backtrack(nums, visited, current, result);
        current.pop_back();
        visited[i] = false;
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) nums[i] = i + 1;
    std::vector<bool> visited(n, false);
    std::string current;
    std::vector<std::string> result;

    backtrack(nums, visited, current, result);
    std::sort(result.begin(), result.end());
    for (const auto& perm : result) {
        std::cout << perm << std::endl;
    }
    return 0;
}
