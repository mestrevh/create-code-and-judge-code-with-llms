/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

/**
 * Merge function to combine two sorted sub-arrays.
 * Maintains stability by using the <= comparison.
 * Time Complexity: O(n)
 * Space Complexity: O(n) (uses auxiliary array)
 */
void merge(vector<int>& arr, int l, int m, int r, vector<int>& aux) {
    int i = l;
    int j = m + 1;
    int k = l;

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            aux[k++] = arr[i++];
        } else {
            aux[k++] = arr[j++];
        }
    }

    while (i <= m) {
        aux[k++] = arr[i++];
    }
    while (j <= r) {
        aux[k++] = arr[j++];
    }

    for (int p = l; p <= r; ++p) {
        arr[p] = aux[p];
    }
}

/**
 * Merge Sort recursive function implementing Divide and Conquer.
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */
void solveMergeSort(vector<int>& arr, int l, int r, vector<int>& aux) {
    if (l < r) {
        int m = l + (r - l) / 2;
        solveMergeSort(arr, l, m, aux);
        solveMergeSort(arr, m + 1, r, aux);
        merge(arr, l, m, r, aux);
    }
}

int main() {
    // Standard I/O optimization for Competitive Programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_vectors;
    if (!(cin >> n_vectors)) return 0;

    string line;
    // Consume the remaining newline from the initial integer read
    getline(cin, line);

    while (n_vectors > 0) {
        if (!getline(cin, line)) break;
        if (line.empty()) continue;

        // Replace potential commas with spaces to ensure robust parsing
        for (char &c : line) {
            if (c == ',') c = ' ';
        }

        stringstream ss(line);
        vector<int> vec;
        int val;
        while (ss >> val) {
            vec.push_back(val);
        }

        if (vec.empty()) continue;

        // Auxiliary array to fulfill the "not in place" O(n) space requirement
        vector<int> aux(vec.size());
        solveMergeSort(vec, 0, (int)vec.size() - 1, aux);

        // Output formatting: space-separated integers, line per vector
        for (int i = 0; i < (int)vec.size(); ++i) {
            cout << vec[i] << (i == (int)vec.size() - 1 ? "" : " ");
        }
        cout << "\n";
        
        n_vectors--;
    }

    return 0;
}