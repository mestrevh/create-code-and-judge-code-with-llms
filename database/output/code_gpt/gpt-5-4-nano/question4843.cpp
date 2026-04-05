/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int binarySearchRec(const vector<int>& a, int target, int l, int r) {
    if (l > r) return -1;
    int mid = l + (r - l) / 2;
    if (a[mid] == target) return mid;
    if (a[mid] > target) return binarySearchRec(a, target, l, mid - 1);
    return binarySearchRec(a, target, mid + 1, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    if (!(cin >> x)) return 0;
    vector<int> a(20);
    for (int i = 0; i < 20; i++) cin >> a[i];

    cout << binarySearchRec(a, x, 0, 19) << "\n";
    return 0;
}