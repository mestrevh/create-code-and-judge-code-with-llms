/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

std::map<long long, int> pos_map;

long long find_pivot(const std::vector<long long>& arr, int start, int end) {
    long long sum = 0;
    for (int i = start; i <= end; ++i) {
        sum += arr[i];
    }
    long long avg_floor = sum / (end - start + 1);

    long long best_pivot = arr[start];
    long long min_diff = std::abs(arr[start] - avg_floor);

    for (int i = start + 1; i <= end; ++i) {
        long long current_val = arr[i];
        long long diff = std::abs(current_val - avg_floor);

        if (diff < min_diff) {
            min_diff = diff;
            best_pivot = current_val;
        } else if (diff == min_diff) {
            if (current_val < best_pivot) {
                best_pivot = current_val;
            }
        }
    }
    return best_pivot;
}

int partition(std::vector<long long>& arr, int start, int end, long long pivot_val) {
    int pivot_original_idx = start;
    while (arr[pivot_original_idx] != pivot_val) {
        pivot_original_idx++;
    }
    std::swap(arr[pivot_original_idx], arr[end]);

    int store_index = start;
    for (int i = start; i < end; ++i) {
        if (arr[i] <= pivot_val) {
            std::swap(arr[i], arr[store_index]);
            store_index++;
        }
    }
    std::swap(arr[store_index], arr[end]);
    return store_index;
}

void custom_quicksort(std::vector<long long>& arr, int start, int end) {
    if (start > end) {
        return;
    }

    long long pivot_val = find_pivot(arr, start, end);
    
    int sorted_pos = pos_map[pivot_val];
    pos_map[pivot_val]--;
    std::cout << "(" << pivot_val << "," << sorted_pos << ")";
    
    if (start == end) {
        return;
    }

    int pivot_final_idx = partition(arr, start, end, pivot_val);

    custom_quicksort(arr, start, pivot_final_idx - 1);
    custom_quicksort(arr, pivot_final_idx + 1, end);
}

void solve() {
    long long n, x0, a, c, m;
    while (std::cin >> n >> x0 >> a >> c >> m) {
        std::vector<long long> arr(n);
        arr[0] = x0;
        for (int i = 1; i < n; ++i) {
            arr[i] = (a * arr[i - 1] + c) % m;
        }

        std::vector<long long> sorted_arr = arr;
        std::sort(sorted_arr.begin(), sorted_arr.end());

        pos_map.clear();
        for (int i = 0; i < n; ++i) {
            pos_map[sorted_arr[i]] = i + 1;
        }
        
        custom_quicksort(arr, 0, n - 1);
        
        std::cout << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
