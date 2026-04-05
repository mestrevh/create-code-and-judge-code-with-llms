/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printArray(const vector<int>& v, int n) {
    for (int i = 0; i < n; ++i) {
        cout << v[i] << (i == n - 1 ? "" : " | ");
    }
}

void max_heapify(vector<int>& A, int n, int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    if (l < n && A[l] > A[largest]) largest = l;
    if (r < n && A[r] > A[largest]) largest = r;
    if (largest != i) {
        swap(A[i], A[largest]);
        max_heapify(A, n, largest);
    }
}

void build_max_heap(vector<int>& A) {
    int n = (int)A.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
        max_heapify(A, n, i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> A;
    int x;
    while (cin >> x) {
        A.push_back(x);
    }
    
    if (A.empty()) return 0;

    cout << "Estado inicial: ";
    printArray(A, (int)A.size());
    cout << "\n";

    build_max_heap(A);

    int n = (int)A.size();
    for (int i = n - 1; i > 0; --i) {
        cout << "Estado Atual da Heap: ";
        printArray(A, i + 1);
        cout << "\n";
        
        cout << "Maior elemento neste passo: " << A[0] << "\n";
        
        swap(A[0], A[i]);
        max_heapify(A, i, 0);
    }
    
    cout << "Estado Atual da Heap: ";
    printArray(A, 1);
    cout << "\n";

    // Standard heapsort logic places the largest element at the end in each step, 
    // so after the loop from i = n-1 down to 1, the entire array is sorted.
    cout << "Resultado Final: ";
    printArray(A, (int)A.size());
    cout << "\n";

    return 0;
}