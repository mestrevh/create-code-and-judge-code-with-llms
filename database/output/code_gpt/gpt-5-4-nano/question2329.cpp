/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<string> names(N);
    vector<long long> need(N);
    for (int i = 0; i < N; i++) {
        cin >> names[i] >> need[i];
    }

    vector<long long> rem = need;

    function<void(int)> process = [&](int idx) {
        if (idx == N) return;
        if (rem[idx] > 0) {
            cout << names[idx] << " foi servido(a).\n";
            rem[idx] -= 400;
            if (rem[idx] > 0) {
                cout << "Fica tranquilo(a), " << names[idx] << " pode se servir novamente!\n";
            }
        }
        process(idx + 1);
    };

    while (true) {
        bool any = false;
        for (int i = 0; i < N; i++) {
            if (rem[i] > 0) {
                any = true;
                break;
            }
        }
        if (!any) break;

        process(0);
    }

    return 0;
}