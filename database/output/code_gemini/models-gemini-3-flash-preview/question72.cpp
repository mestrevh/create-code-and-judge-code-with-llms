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

    int N;
    if (!(cin >> N)) return 0;

    if (N <= 0) {
        cout << "\n";
        return 0;
    }

    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    for (int i = N - 1; i >= 0; --i) {
        cout << arr[i] << (i == 0 ? "" : " ");
    }
    cout << "\n";

    return 0;
}