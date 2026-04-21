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
    cin >> n2;
    
    vector<long long> a(n1), b(n2);
    for (int i = 0; i < n1; i++) cin >> a[i];
    for (int i = 0; i < n2; i++) cin >> b[i];
    
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            cout << a[i] << "\n";
            i++;
        } else {
            cout << b[j] << "\n";
            j++;
        }
    }
    while (i < n1) {
        cout << a[i] << "\n";
        i++;
    }
    while (j < n2) {
        cout << b[j] << "\n";
        j++;
    }
    return 0;
}