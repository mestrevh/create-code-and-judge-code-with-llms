/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static void maxHeapify(vector<long long>& a, int i, int heapSize) {
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> a;
    long long x;
    while (cin >> x) a.push_back(x);
    int n = (int)a.size();

    auto printHeap = [&](const vector<long long>& v) {
        for (int i = 0; i < (int)v.size(); i++) {
            if (i) cout << " | ";
            cout << v[i];
        }
        cout << "\n";
    };

    cout << "Estado inicial: ";
    printHeap(a);

    for (int i = n / 2 - 1; i >= 0; --i) {
        maxHeapify(a, i, n);
        cout << "Estado Atual: ";
        printHeap(a);
    }

    cout << "Resultado Final: ";
    printHeap(a);

    return 0;
}