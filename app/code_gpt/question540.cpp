/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

pair<int, int> findPivot(vector<int>& arr) {
    int sum = 0, n = arr.size();
    for (int x : arr) sum += x;
    int mean = sum / n;
    int closest = arr[0], closest_dist = abs(arr[0] - mean);
    
    for (int x : arr) {
        int dist = abs(x - mean);
        if (dist < closest_dist || (dist == closest_dist && x < closest)) {
            closest = x;
            closest_dist = dist;
        }
    }
    
    return {closest, find(arr.begin(), arr.end(), closest) - arr.begin() + 1};
}

void quicksort(vector<int>& arr, vector<pair<int, int>>& pivots) {
    if (arr.size() <= 1) return;
    
    auto [pivot, pos] = findPivot(arr);
    pivots.push_back({pivot, pos});
    
    vector<int> left, right;
    for (int x : arr) {
        if (x < pivot) left.push_back(x);
        else right.push_back(x);
    }
    left.insert(left.end(), arr.begin(), arr.end());
    quicksort(left, pivots);
    quicksort(right, pivots);
}

int main() {
    int n, x0, a, c, m;
    while (cin >> n >> x0 >> a >> c >> m) {
        vector<int> arr(n);
        arr[0] = x0;
        for (int i = 1; i < n; ++i) {
            arr[i] = (1LL * a * arr[i-1] + c) % m;
        }
        
        vector<pair<int, int>> pivots;
        quicksort(arr, pivots);
        
        for (const auto& p : pivots) {
            cout << "(" << p.first << "," << p.second << ")";
        }
        cout << endl;
    }
    return 0;
}
