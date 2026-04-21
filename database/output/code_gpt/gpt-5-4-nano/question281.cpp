/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L;
    while (cin >> L) {
        vector<int> a(L);
        for (int i = 0; i < L; i++) cin >> a[i];

        long long inv = 0;
        for (int i = 0; i < L; i++) {
            for (int j = i + 1; j < L; j++) {
                if (a[i] > a[j]) inv++;
            }
        }

        cout << "A melhor troca leva " << inv << " passos\n";
    }
    return 0;
}