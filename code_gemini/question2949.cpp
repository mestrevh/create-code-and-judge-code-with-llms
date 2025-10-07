/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

void solve(int case_num) {
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
        sum += nums[i];
    }

    std::sort(nums.begin(), nums.end());

    std::cout << "sequencia " << case_num << ":" << std::endl;

    for (int x : nums) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    std::cout << nums[0] << " " << nums.back() << std::endl;

    double mean = sum / n;
    std::cout << mean << std::endl;

    if (n > 0) {
        std::map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }

        int max_freq = 0;
        for (const auto& pair : freq) {
            if (pair.second > max_freq) {
                max_freq = pair.second;
            }
        }

        if (max_freq > 1) {
            for (const auto& pair : freq) {
                if (pair.second == max_freq) {
                    std::cout << pair.first << " ";
                }
            }
        }
    }
    std::cout << std::endl;

    double median;
    if (n % 2 != 0) {
        median = nums[n / 2];
    } else {
        median = (static_cast<double>(nums[n / 2 - 1]) + nums[n / 2]) / 2.0;
    }
    std::cout << median << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int c;
    std::cin >> c;
    for (int i = 1; i <= c; ++i) {
        solve(i);
    }

    return 0;
}
