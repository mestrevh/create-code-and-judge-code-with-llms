/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

/**
 * QuickSort implementation following the properties:
 * - Divide and Conquer
 * - Not stable
 * - In-place
 * - O(n log n) best and average case
 * - O(1) auxiliary space (excluding recursion stack)
 */
void quick_sort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    
    int i = left, j = right;
    // Pivot selection: middle element to mitigate O(n^2) on nearly sorted data
    int pivot = arr[left + (right - left) / 2];
    
    // Hoare partition scheme
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    
    if (left < j) quick_sort(arr, left, j);
    if (i < right) quick_sort(arr, i, right);
}

int main() {
    // Fast I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    string line;
    getline(cin, line); // Consume the remaining newline after N

    while (N--) {
        if (!getline(cin, line)) break;
        if (line.empty()) {
            // Some input files might have empty lines between cases
            N++;
            continue;
        }

        // Sanitize input: replace commas with spaces to handle both "1, 2, 3" and "1 2 3"
        for (char &c : line) {
            if (c == ',') c = ' ';
        }

        stringstream ss(line);
        vector<int> vec;
        int num;
        while (ss >> num) {
            vec.push_back(num);
        }

        if (!vec.empty()) {
            quick_sort(vec, 0, (int)vec.size() - 1);

            for (int i = 0; i < (int)vec.size(); ++i) {
                cout << vec[i] << (i == (int)vec.size() - 1 ? "" : " ");
            }
            cout << "\n";
        }
    }

    return 0;
}