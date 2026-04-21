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

    const int N = 10;
    vector<int> a(N);
    vector<int> b(N);

    for (int i = 0; i < N; ++i) {
        if (!(cin >> a[i])) break;
    }

    for (int i = 0; i < N; ++i) {
        if (!(cin >> b[i])) break;
    }

    for (int i = 0; i < N; ++i) {
        cout << a[i] + b[i] << (i == N - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}