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

    int V, N;
    if (!(cin >> V >> N)) return 0;

    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    bool found = false;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            for (int k = j + 1; k < N; ++k) {
                if (a[i] + a[j] + a[k] == V) {
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        if (found) break;
    }

    if (found) {
        cout << "Zeca nao vai ter que trabalhar!";
    } else {
        cout << "Zeca vai ter que trabalhar.";
    }

    return 0;
}