/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> L(N);
    L[0] = 1;
    for (int i = 1; i < N; ++i) {
        L[i] = min(A[i], L[i - 1] + 1);
    }

    vector<int> R(N);
    R[N - 1] = 1;
    for (int i = N - 2; i >= 0; --i) {
        R[i] = min(A[i], R[i + 1] + 1);
    }

    int max_h = 0;
    for (int i = 0; i < N; ++i) {
        int h = min(L[i], R[i]);
        if (h > max_h) {
            max_h = h;
        }
    }

    cout << max_h << endl;

    return 0;
}

