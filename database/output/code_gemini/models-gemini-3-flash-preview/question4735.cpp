/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Perform Min-Heapify on a subtree rooted with node i which is
 * an index in arr[]. n is size of heap.
 */
void minHeapify(vector<long long>& arr, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

/**
 * Heap Sort function using a Min-Heap.
 * Since it's a Min-Heap, extracting the minimum and placing it 
 * at the end of the array results in a descending order.
 */
void heapSort(vector<long long>& arr) {
    int n = arr.size();

    // Build min heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root (minimum) to end
        swap(arr[0], arr[i]);

        // call minHeapify on the reduced heap
        minHeapify(arr, i, 0);
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<long long> original;
    long long val;

    // Reading numerical sequence until EOF
    while (cin >> val) {
        original.push_back(val);
    }

    if (original.empty()) return 0;

    // Display original array message and contents
    // Based on test case: "Array original:" followed by values with trailing space
    cout << "Array original:" << "\n";
    for (size_t i = 0; i < original.size(); ++i) {
        cout << original[i] << " ";
    }
    cout << "\n";

    // Prepare array for sorting
    vector<long long> sorted = original;
    heapSort(sorted);

    // Display sorted array message and contents
    // Based on test case: "Array ordenado" (no colon) followed by values without trailing space
    cout << "Array ordenado" << "\n";
    for (size_t i = 0; i < sorted.size(); ++i) {
        cout << sorted[i] << (i == sorted.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}