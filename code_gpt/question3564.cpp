/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        if (a[0] > d) {
            cout << "NAO" << endl;
        } else if (a[1] + a[2] <= d) {
            cout << "SIM" << endl;
        } else {
            cout << "NAO" << endl;
        }
    }
    return 0;
}
