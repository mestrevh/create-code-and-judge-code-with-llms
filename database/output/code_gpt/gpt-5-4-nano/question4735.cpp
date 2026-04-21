/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> a;
    long long x;
    while (cin >> x) a.push_back(x);

    vector<long long> b = a;

    auto heapify = [&](int n, int i, auto&& heapify_ref) -> void {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && b[l] > b[largest]) largest = l;
        if (r < n && b[r] > b[largest]) largest = r;

        if (largest != i) {
            swap(b[i], b[largest]);
            heapify_ref(n, largest, heapify_ref);
        }
    };

    int n = (int)b.size();
    for (int i = n / 2 - 1; i >= 0; --i) heapify(n, i, heapify);
    for (int i = n - 1; i > 0; --i) {
        swap(b[0], b[i]);
        heapify(i, 0, heapify);
    }

    cout << "Array original:\n";
    for (size_t i = 0; i < a.size(); ++i) cout << a[i] << ' ';
    cout << "\nArray ordenado\n";
    for (size_t i = 0; i < b.size(); ++i) cout << b[i] << (i + 1 == b.size() ? '\n' : ' ');

    return 0;
}