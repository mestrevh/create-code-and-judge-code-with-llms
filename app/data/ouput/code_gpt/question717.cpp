/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    vector<int> arr;

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            int x;
            cin >> x;
            arr.push_back(x);
        }
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << arr[i * N + j] << " ";
        }
        cout << endl;
    }

    return 0;
}
