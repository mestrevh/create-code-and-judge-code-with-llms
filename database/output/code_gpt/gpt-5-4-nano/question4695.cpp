/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static void printVector(const vector<long long>& a) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (i) cout << ' ';
        cout << a[i];
    }
    cout << "\n";
}

static void quickSortStep(vector<long long>& a, int l, int r) {
    if (l > r) return;

    int pivotIndex = r;
    long long pivot = a[pivotIndex];

    cout << "Subarray: ";
    for (int i = l; i <= r; ++i) {
        if (i != l) cout << ' ';
        cout << a[i];
    }
    cout << " \n";
    cout << "Pivo: " << pivot << "\n";

    int i = l - 1;
    for (int j = l; j <= r - 1; ++j) {
        if (a[j] <= pivot) {
            ++i;
            swap(a[i], a[j]);
        }
    }
    ++i;
    swap(a[i], a[r]);

    cout << "Array: ";
    printVector(a);

    quickSortStep(a, l, i - 1);
    quickSortStep(a, i + 1, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> a;
    long long x;
    while (cin >> x) a.push_back(x);

    if (!a.empty()) quickSortStep(a, 0, (int)a.size() - 1);
    return 0;
}