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

void printArray(const string& label, const vector<int>& A) {
    cout << label << ": ";
    for (size_t i = 0; i < A.size(); ++i) {
        cout << A[i];
        if (i < A.size() - 1) {
            cout << " | ";
        }
    }
    cout << "\n";
}

void max_heapify(vector<int>& A, int i, int heap_size) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    if (l < heap_size && A[l] > A[largest]) {
        largest = l;
    }
    if (r < heap_size && A[r] > A[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(A[i], A[largest]);
        max_heapify(A, largest, heap_size);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    if (!getline(cin, line)) return 0;
    
    stringstream ss(line);
    vector<int> A;
    int val;
    while (ss >> val) {
        A.push_back(val);
    }

    if (A.empty()) return 0;

    printArray("Estado inicial", A);

    int n = static_cast<int>(A.size());
    // In Cormen, build-max-heap runs from floor(n/2) down to 1 (1-based)
    // In 0-based indexing, this is from floor(n/2) - 1 down to 0
    for (int i = n / 2 - 1; i >= 0; --i) {
        max_heapify(A, i, n);
        printArray("Estado Atual", A);
    }

    printArray("Resultado Final", A);

    return 0;
}