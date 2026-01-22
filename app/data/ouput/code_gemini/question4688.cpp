/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int target;
    std::cin >> target;

    std::vector<int> arr;
    int num;
    while (std::cin >> num) {
        arr.push_back(num);
    }

    int low = 0;
    int high = arr.size() - 1;
    int index = -1;
    int operations = 0;

    while (low <= high) {
        operations++;
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            index = mid;
            break;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    std::cout << index << std::endl;

    if (index == -1) {
        int n = arr.size();
        if (n > 0) {
            operations = static_cast<int>(floor(log2(n))) + 1;
        } else {
            operations = 0;
        }
    }

    std::cout << std::max(1, operations) << std::endl;

    return 0;
}
