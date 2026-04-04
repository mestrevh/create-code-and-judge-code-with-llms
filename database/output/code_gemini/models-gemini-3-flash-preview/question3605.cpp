/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v;
    int val;
    while (cin >> val) {
        v.push_back(val);
    }

    if (v.empty()) return 0;

    int n = (int)v.size();
    int p = 0;
    int r = n - 1;
    int mid = p + (r - p) / 2;

    int a = v[p];
    int b = v[mid];
    int c = v[r];

    int pivotIdx;
    if ((a <= b && b <= c) || (c <= b && b <= a)) {
        pivotIdx = mid;
    } else if ((b <= a && a <= c) || (c <= a && a <= b)) {
        pivotIdx = p;
    } else {
        pivotIdx = r;
    }

    int pivot = v[pivotIdx];
    swap(v[pivotIdx], v[r]);

    int i = p;
    for (int j = p; j < r; j++) {
        if (v[j] <= pivot) {
            swap(v[i], v[j]);
            i++;
        }
    }
    swap(v[i], v[r]);

    cout << pivot << "\n";
    for (int k = 0; k < n; k++) {
        cout << v[k] << (k == n - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}