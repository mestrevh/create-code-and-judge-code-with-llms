/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long E;
    int K, N;

    if (!(cin >> E >> K >> N)) return 0;

    bool exhausted = false;
    for (int i = 1; i <= N; ++i) {
        int SE, SA, DO;
        if (!(cin >> SE >> SA >> DO)) break;

        long long weekly_demand = 4LL * K + SE + SA + DO;
        E -= weekly_demand;

        if (E <= 0) {
            cout << i << " " << E << "\n";
            exhausted = true;
            break;
        }
    }

    if (!exhausted) {
        cout << E << "\n";
    }

    return 0;
}

