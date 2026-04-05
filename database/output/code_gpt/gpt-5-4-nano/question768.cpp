/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n1, n2;
    if (!(cin >> n1)) return 0;
    vector<int> a(n1);
    for (int i = 0; i < n1; i++) cin >> a[i];

    cin >> n2;
    vector<int> b(n2);
    for (int i = 0; i < n2; i++) cin >> b[i];

    int i = n1 - 1, j = n2 - 1;
    int carry = 0;
    vector<int> res;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--];
        if (j >= 0) sum += b[j--];
        res.push_back(sum % 10);
        carry = sum / 10;
    }

    for (int k = (int)res.size() - 1; k >= 0; k--) cout << res[k];
    return 0;
}