/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v;
    int val;
    while (cin >> val) {
        v.push_back(val);
    }

    if (v.empty()) {
        return 0;
    }

    int minVal = v[0];
    int maxVal = v[0];
    for (size_t i = 1; i < v.size(); ++i) {
        if (v[i] < minVal) minVal = v[i];
        if (v[i] > maxVal) maxVal = v[i];
    }

    double m = (double(maxVal) + double(minVal)) / 2.0;

    int pivotIdx = -1;
    double minDiff = -1.0;
    for (size_t i = 0; i < v.size(); ++i) {
        double diff = std::abs(double(v[i]) - m);
        if (pivotIdx == -1 || diff < minDiff) {
            minDiff = diff;
            pivotIdx = (int)i;
        }
    }

    int pivotVal = v[pivotIdx];
    cout << pivotVal << "\n";

    // Implement Lomuto Partitioning
    // Move the selected pivot to the end of the array
    swap(v[pivotIdx], v[v.size() - 1]);

    int i = -1;
    // Iterate through the array up to the element before the pivot
    for (size_t j = 0; j < v.size() - 1; ++j) {
        // Elements less than or equal to the pivot go to the left part
        if (v[j] <= pivotVal) {
            i++;
            swap(v[i], v[j]);
        }
    }
    // Place the pivot in its final sorted position (i+1)
    swap(v[i + 1], v[v.size() - 1]);

    // Output the partitioned array
    for (size_t k = 0; k < v.size(); ++k) {
        cout << v[k] << (k == v.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}