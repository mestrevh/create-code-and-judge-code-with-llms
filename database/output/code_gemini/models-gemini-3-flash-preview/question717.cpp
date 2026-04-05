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

    int M, N;
    if (!(cin >> M >> N)) {
        return 0;
    }

    int total_elements = M * N;
    vector<int> vec(total_elements);

    for (int i = 0; i < total_elements; ++i) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << vec[i * N + j] << (j == N - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}