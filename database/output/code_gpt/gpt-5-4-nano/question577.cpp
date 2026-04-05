/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static void printHeap(const vector<long long>& a, int heapSize) {
    for (int i = 0; i < heapSize; i++) {
        if (i) cout << " | ";
        cout << a[i];
    }
}

static void maxHeapify(vector<long long>& a, int heapSize, int i) {
    while (true) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int largest = i;
        if (l < heapSize && a[l] > a[largest]) largest = l;
        if (r < heapSize && a[r] > a[largest]) largest = r;
        if (largest == i) break;
        swap(a[i], a[largest]);
        i = largest;
    }
}

static void buildMaxHeap(vector<long long>& a, int heapSize) {
    for (int i = heapSize / 2 - 1; i >= 0; i--) {
        maxHeapify(a, heapSize, i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> a;
    long long x;
    bool first = true;
    while (cin >> x) a.push_back(x);

    int n = (int)a.size();
    if (n == 0) return 0;

    cout << "Estado inicial: ";
    printHeap(a, n);
    cout << "\n";

    buildMaxHeap(a, n);

    int heapSize = n;
    cout << "Estado Atual da Heap: ";
    printHeap(a, heapSize);
    cout << "\n";

    while (heapSize > 1) {
        cout << "Maior elemento neste passo: " << a[0] << "\n";
        swap(a[0], a[heapSize - 1]);
        heapSize--;
        cout << "Estado Atual da Heap: ";
        printHeap(a, heapSize);
        cout << "\n";
        maxHeapify(a, heapSize, 0);
    }

    if (heapSize == 1) {
        cout << "Maior elemento neste passo: " << a[0] << "\n";
        cout << "Estado Atual da Heap: ";
        printHeap(a, heapSize);
        cout << "\n";
    }

    cout << "Resultado Final: ";
    printHeap(a, n);
    cout << "\n";
    return 0;
}