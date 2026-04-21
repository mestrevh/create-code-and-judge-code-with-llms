/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> pares;
    vector<int> impares;
    pares.reserve(n);
    impares.reserve(n);

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x % 2 == 0) {
            pares.push_back(x);
        } else {
            impares.push_back(x);
        }
    }

    for (int i = 0; i < (int)pares.size(); ++i) {
        cout << "pares[" << i << "] = " << pares[i] << "\n";
    }

    for (int i = 0; i < (int)impares.size(); ++i) {
        cout << "impares[" << i << "] = " << impares[i] << "\n";
    }

    return 0;
}